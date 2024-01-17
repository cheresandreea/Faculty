module com.exampe.demo3 {
    requires javafx.controls;
    requires javafx.fxml;
    opens Model.DataTransfer to javafx.base;
    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;
    requires jdk.javadoc;
    requires java.management;
    requires java.desktop;

    opens Gui to javafx.fxml;
    exports Gui;
}