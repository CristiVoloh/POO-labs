package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

public class Controller {

    @FXML
    private TextField label1;

    @FXML
    private TextField label2;

    @FXML
    private Button solveButton;

    @FXML
    private TextArea outputField;

    double input1 = 0, input2 = 0, result = 0;

    public void solve(ActionEvent event){
        input1 = Double.parseDouble(label1.getText());
        input2 = Double.parseDouble(label2.getText());
        outputField.setStyle("-fx-text-fill: black;");
        result = (input1 / input2);

        try{
            if(input2 == 0) {
                outputField.setStyle("-fx-text-fill: red;");
                outputField.setText("Wrong numbers!");
            }
            else if(result == 13) {
                throw new UnluckyException("UnluckyException(13)");
            }
            else if ((input1 % input2) == 0) {
                outputField.setText(String.valueOf((int)result));
            }
            else {
                outputField.setText(String.valueOf(result));
            }
        } catch (UnluckyException unluckyException) {
            outputField.setStyle("-fx-text-fill: red;");
            outputField.setText("Unlucky exception (13)");
        }
    }

}
