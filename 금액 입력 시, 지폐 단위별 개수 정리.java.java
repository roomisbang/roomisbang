import java.util.Scanner;
public class midrep1 {

    public static void main(String[] args) {
        Scanner scn = new Scanner (System.in);
        
        
        // 정수 값으로 금액을 입력 
        System.out.print("금액을 입력하세요 >> ");
        int input_number = scn.nextInt ();
        
        // 5만원권 부터
        if (input_number >= 50000){
            int fifty_thousnad = input_number / 50000;
            input_number = input_number % 50000;
            System.out.println("5만원 권:"+ fifty_thousnad +"장");
        }
        else {
            System.out.println("5만원 권: 0장");
        }

        // 1만원권
        if (input_number >= 10000){
            int ten_thousnad = input_number / 10000;
            input_number = input_number % 10000;
            System.out.println("1만원 권:"+ ten_thousnad +"장");
        }
        else {
            System.out.println("1만원 권: 0장");
        }
        // 5천원권
        if (input_number >= 5000){
            int five_thousnad = input_number / 5000;
            input_number = input_number % 5000;
            System.out.println("5천원 권:"+ five_thousnad +"장");
        }
        else {
            System.out.println("5천원 권: 0장");
        }
        // 천원권
        if (input_number >= 1000){
            int thousnad = input_number / 1000;
            input_number = input_number % 1000;
            System.out.println("천원 권:"+ thousnad +"장");
        }
        else {
            System.out.println("천원 권: 0장");
        }
        // 오백원 동전
        if (input_number >= 500){
            int five_hundred = input_number / 500;
            input_number = input_number % 500;
            System.out.println("오백원 동전:"+ five_hundred +"개");
        }
        else {
            System.out.println("오백원 동전: 0개");
        }
        // 백원 동전
        if (input_number >= 100){
            int hundred = input_number / 100;
            input_number = input_number % 100;
            System.out.println("백원 동전:"+ hundred +"개");
        }
        else {
            System.out.println("오백원 동전: 0개");
        }
        // 오십원 동전
        if (input_number >= 50){
            int fifty = input_number / 50;
            input_number = input_number % 50;
            System.out.println("오십원 동전:"+ fifty +"개");
        }
        else {
            System.out.println("오십원 동전: 0개");
        }
        // 십원 동전
        if (input_number >= 10){
            int ten = input_number / 10;
            input_number = input_number % 10;
            System.out.println("십원 동전:"+ ten +"개");
        }
        else {
            System.out.println("십원 동전: 0개");
        }
        // 일원 동전
        if (input_number >= 1){
            int one = input_number / 1;
            input_number = input_number % 1;
            System.out.println("일원 동전:"+ one +"개");
        }
        else {
            System.out.println("일원 동전: 0개");
        }

        return;
    }
}