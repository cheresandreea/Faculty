package Controller;

import Model.Exceptions.MyException;
import Model.State.programState;
import Model.Values.iValue;
import Model.Values.refValue;
import Repository.iRepository;
import jdk.javadoc.doclet.Reporter;

import javax.management.loading.ClassLoaderRepository;
import java.beans.IntrospectionException;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.concurrent.*;
import java.util.stream.Collectors;

public class Controller implements iController
{
    iRepository repository;
    ExecutorService executor;

    public Controller(iRepository repository)
    {
        this.repository = repository;
    }

    Map<Integer, iValue> unsafeGarbageCollector(List<Integer> symTableAddr, Map<Integer,iValue> heap)
    {
        return heap.entrySet()
                .stream()
                .filter(e->symTableAddr.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }
//    List<Integer> getAddrFromSymTableFunctional(Collection<iValue> symTableValues)
//    {
//        return symTableValues.stream()
//                .filter(v-> v instanceof refValue)
//                .map(v-> {refValue v1 = (refValue)v; return v1.getAddr();})
//                .collect(Collectors.toList());
//    }

    List<Integer> getAddrFromSymTable(Collection<iValue> symTableValues, Map<Integer, iValue> heap)
    {
        List<Integer> addresses = new java.util.ArrayList<>();
        for (iValue value : symTableValues)
        {
            while (value instanceof refValue ref)
            {
                int address = ref.getAddr();
                addresses.add(address);
                value = heap.get(address);
            }
        }
        return addresses;
    }


    @Override
    public void executeAll(List<programState> prgList) throws InterruptedException {

        executor = Executors.newFixedThreadPool(2);
        //before the execution, print the PrgState List into the log file
        prgList.forEach(prg-> {
            try {
                repository.logProgramStateExecution(prg);
            } catch (MyException e) {
                throw new RuntimeException(e);
            }
        });

        //prepare the list of callables
        List<Callable<programState>> callList = prgList.stream()
                .map((programState p) -> (Callable<programState>)( p::executeOneStep))
                .collect(Collectors.toList());

        //start the execution of the callables
        //it returns the list of new created PrgStates (namely threads)
        List<programState> newProgramsList = executor.invokeAll(callList).stream()
                .map(future->
                        {
                            try{
                                return future.get();
                            }catch (ExecutionException | InterruptedException ex){
                                System.out.println(ex.toString());
                            }
                            return null;
                        })
                .filter(p->p!=null)
                .collect(Collectors.toList());

        //add the new created threads to the list of existing threads
        prgList.addAll(newProgramsList);

        //after the execution, print the PrgState List into the log file
        prgList.forEach(p->{
            try{
                this.repository.logProgramStateExecution(p);
            }catch (MyException e){
                e.printStackTrace();
            }
        });

        //Save the current programs in the repository
        this.repository.setProgramList(prgList);


    }

    public void oneStep() throws MyException{
        executor = Executors.newFixedThreadPool(2);

        //remove the completed programs
        List <programState> programs = removeCompletedPrg(repository.getProgramList());

        while(programs.size() > 0){
            Collection<iValue> addresses = programs.stream()
                    .flatMap(program -> program.getSymbolTable().getContent().values().stream())
                    .collect(Collectors.toList());

            //programs.get(0).getHeap().set(unsafeGarbageCollector(getAddrFromSymTable(addresses,programs.get(0).getHeap().getContent()), getAddrFromSymTable(programs.get(0).getHeap().getContent(), addresses)), programs.get(0));
            programs.get(0).getHeap().set(unsafeGarbageCollector(getAddrFromSymTable(addresses,programs.get(0).getHeap().getContent()), programs.get(0).getHeap().getContent()));

            try{
                this.executeAll(programs);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }

            programs = removeCompletedPrg(repository.getProgramList());
        }
        executor.shutdownNow();
        repository.setProgramList(programs);
    }

    public List<programState> removeCompletedPrg(List<programState> inPrgList)
    {
        return inPrgList.stream()
                .filter(p->p.isNotCompleted())
                //returns programs that have a nonempty exeStack
                .collect(Collectors.toList());
    }

    public iRepository getRepo() {
        return repository;
    }
}
