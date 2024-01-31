#include "Repo.h"
#include "fstream"
#include "iostream"
#include <windows.h>
#include "ValidationException.h"


RepoFileHTML::RepoFileHTML() : Repo() {}

RepoFileHTML::~RepoFileHTML() {}


void RepoFileHTML::saveAdoptedDogsToSpecificFile()
{
    std::ofstream file("Dogs.html"); // Open the file in write mode

    if (file.is_open()) {
        file << R"(
<!DOCTYPE html>
<html>
<head>
    <title>Dogs</title>
</head>
<body>
<table border="1">
    <tr>
        <td>Breed</td>
        <td>Name</td>
        <td>Age</td>
        <td>Photo link</td>
    </tr>)";

        // Generate table rows dynamically based on the adoptedDogs vector
        for (const auto& dog : adoptedDogs) {
            file << "<tr>";
            file << "<td>" << dog.getBreed() << "</td>";
            file << "<td>" << dog.getName() << "</td>";
            file << "<td>" << dog.getAge() << "</td>";
            file << "<td><a href=\"" << dog.getPhotography() << "\">Link</a></td>";
            file << "</tr>\n";
        }

        file << R"(
</table>
</body>
</html>)";

        std::string path = "Dogs.html";
        open(path);

        file.close();
        std::cout << "File saved successfully.\n";
    }
    else {
       
       throw FileWriteException("An error occurred while writing to the file.");
       
    }
}

vector<Dog> RepoFileHTML::getAdoptedDogsRepo()
{
    return adoptedDogs;
}

void RepoFileHTML::open(std::string& path)
{
    ShellExecute(nullptr, "open", path.c_str(), nullptr, nullptr, SW_SHOWNORMAL);

}
void RepoFileHTML::adoptDogRepo(Dog& d)
{
    this->adoptedDogs.push_back(d);
}