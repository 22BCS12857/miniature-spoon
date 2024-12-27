public class NthTribo {
    public static void main(String[] args){
        int n=4;
        Tribo_Solution s=new Tribo_Solution();
        System.out.println(s.tribonacci(n));
    }
}
class Tribo_Solution {
    // Calculates the n-th Tribonacci number
    public int tribonacci(int n) {
        // Base cases for n = 0, 1, 2
        if (n == 0) {
            return 0;
        }
        if (n < 3) {
            return 1;
        }
        // Transformation matrix for Tribonacci sequence
        int[][] transformationMatrix = {{1, 1, 0}, {1, 0, 1}, {1, 0, 0}};
        // Calculate the power of the matrix to (n-3), since we know the first three values
        int[][] resultingMatrix = matrixPower(transformationMatrix, n - 3);
        // Initialize answer
        int answer = 0;
        // Add the top row of the matrix to get the answer
        for (int element : resultingMatrix[0]) {
            answer += element;
        }
        return answer;
    }

    // Multiplies two matrices and returns the result
    private int[][] matrixMultiply(int[][] a, int[][] b) {
        int rows = a.length, cols = b[0].length;
        int[][] resultMatrix = new int[rows][cols];
        // Perform matrix multiplication
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                for (int k = 0; k < b.length; ++k) {
                    resultMatrix[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return resultMatrix;
    }

    // Calculates the matrix exponentiation of matrix 'a' raised to the power of 'n'
    private int[][] matrixPower(int[][] a, int n) {
        // Create an identity matrix for initial result
        int[][] result = {{1, 1, 0}};
        // Loop to do binary exponentiation
        while (n > 0) {
            // Multiply with 'a' when the least significant bit is 1
            if ((n & 1) == 1) {
                result = matrixMultiply(result, a);
            }
            // Square the matrix 'a'
            a = matrixMultiply(a, a);
            // Right shift 'n' to process the next bit
            n >>= 1;
        }
        return result;
    }
}