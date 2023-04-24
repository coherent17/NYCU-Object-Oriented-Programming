// Matrix.h
class Matrix {
   private:
    double** data;
    int row;
    int col;

   public:
    // Level 1
    // Constructors and destructor
    Matrix();                                  // Set row and col to 0, data to nullptr
    Matrix(int row, int col);                  // Create a zero matrix
    Matrix(int row, int col, double** arr2D);  // Copy from array
    Matrix(const Matrix& matrix);              // Copy from another matrix
    ~Matrix();                                 // Delete data

    // Setters and Getters
    // Set the value of the given row and col
    void setValue(int rowIdx, int colIdx, double value);
    // Get the value of the given row and col
    double getValue(int rowIdx, int colIdx) const;

    // Transpose
    Matrix transpose() const;  // Return a new transposed matrix

    // Operator Overload
    // Overload =, +=, -=, +, -, +m, -m, ==, !=, ostream<<
    // operator=();   // Copy to a new matrix
    // operator+=();  // Matrix addition, ex: a += b;
    // operator-=();  // Matrix subtraction, ex: a -= b;
    // operator+();   // Matrix addition, ex: c = a + b;
    // operator-();   // Matrix subtraction, ex: c = a - b;
    // operator+();   // Positive Matrix, ex: Matrix b = +a;
    // operator-();   // Negative Matrix, ex: Matrix b = -a;
    // operator==();  // Return true if the two matrix is equal
    // operator!=();  // Return false if the two matrix is equal
    // operator<<();  // Output the matrix, ex: cout << a;

    // Level 2
    // Overload *=, *
    // operator*=(Matrix); // Matrix and Matrix multiplication
    // operator*=(double); // Matrix and double multiplication
    // operator*(Matrix); // Matrix and Matrix multiplication
    // operator*(double); // Matrix and double multiplication
    // operator*(double, matrix); // double and Matrix multiplication

    // Level 3
    double determinant() const;  // The determinant of the matrix
};