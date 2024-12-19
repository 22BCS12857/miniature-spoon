import numpy as np

# Function to perform matrix addition or multiplication
def operate(mat1, mat2, operation="add"):
    if operation == "add":
        # Check if dimensions match for addition
        if mat1.shape != mat2.shape:
            raise ValueError("Matrices must have the same dimensions for addition!")
        # Perform matrix addition
        return mat1 + mat2
    
    elif operation == "multiply":
        # Check if multiplication is possible
        if mat1.shape[1] != mat2.shape[0]:
            raise ValueError("Number of columns of the first matrix must equal the number of rows of the second matrix!")
        # Perform matrix multiplication
        return np.dot(mat1, mat2)
    
    else:
        raise ValueError("Invalid operation. Use 'add' or 'multiply'.")

# Function to display a matrix
def display_matrix(matrix):
    for row in matrix:
        print(" ".join(map(str, row)))

# Example usage
if __name__ == "__main__":
    # Example matrices for addition
    mat1 = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    mat2 = np.array([[9, 8, 7], [6, 5, 4], [3, 2, 1]])
    
    # Matrix Addition
    print("Matrix Addition:")
    addition_result = operate(mat1, mat2, operation="add")
    display_matrix(addition_result)
    print()
    
    # Example matrices for multiplication
    mat3 = np.array([[1, 2], [3, 4]])
    mat4 = np.array([[5, 6], [7, 8]])
    
    # Matrix Multiplication
    print("Matrix Multiplication:")
    multiplication_result = operate(mat3, mat4, operation="multiply")
    display_matrix(multiplication_result)
