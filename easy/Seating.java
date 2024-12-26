package easy;
import java.util.Arrays;

public class Seating {
        public static int minMovesToSeat(int[] seats, int[] students) {
        // Sort the arrays to match student-seat pairs by their order.
        Arrays.sort(seats);
        Arrays.sort(students);
        // Initialize the count of moves to zero.
        int totalMoves = 0;
        // Iterate over the arrays to match each student to a seat
        for (int i = 0; i < seats.length; ++i) {
            totalMoves += Math.abs(seats[i] - students[i]);
        }
        // Return the total number of moves required to seat all students.
        return totalMoves;
    }
    public static void main(String[] args){
        //Case 1
        int seats_1[]={3,1,5};
        int students_1[]={2,7,4};
        int res=minMovesToSeat(seats_1, students_1);
        System.out.println("Case 1: " + res);//Expected Output: 4
        //Case 2
        int seats[]={4,1,5,9};
        int students[]={1,3,2,6};
        int res_0=minMovesToSeat(seats, students);
        System.out.println("Case 2: " + res_0);//Expected Output: 7
    } 
}
