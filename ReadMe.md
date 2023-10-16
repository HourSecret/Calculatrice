# Web Calculator App with C++ Backend and SQLite Database and html/csss(tailwind) frontend

**This web application provides a simple calculator interface with a C++ backend that provides 
          basic arithmetic operations and supports complex arithmetic expressions.
**It features a user-friendly interface built with HTML, CSS (Tailwind CSS), and JavaScript.
**The backend logic, written in C++ using the Crow micro web framework, handles calculations and stores the results in an SQLite database.

## Features
-Basic Arithmetic Operations: Addition, Subtraction, Multiplication, Division.
- Support for Complex Arithmetic Expressions.
- Storage of calculation results in an SQLite database.
- Displaying the calculation results on the web interface.

## Technologies Used

- **C++:** Backend logic and RESTful API.
- **Crow:** C++ micro web framework for the server.
- **SQLiteCpp:** C++ wrapper for SQLite database.
- **HTML/CSS/JavaScript:** Frontend user interface.
- 


## Getting Started

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/web-calculator-app.git
    ```

2. Build and run the C++ server:

    ```bash
    cd web-calculator-app/server
    mkdir build && cd build
    cmake ..
    make
    ./calculator-app
    ```

3. Open `public/index.html` in a web browser.

4. Use the calculator to perform basic arithmetic operations and complex expressions.
## Calculator Operations

The calculator supports the following operations:

- **Addition:** `+`
- **Subtraction:** `-`
- **Multiplication:** `*`
- **Division:** `/`
- **Parentheses:** `(` and `)`
### Calculate

- **Endpoint:** `/api/calculate`
- **Method:** POST
- **Request Payload:**
  ```json
  {
    "expression": "2+43/5*(2+98)"
  }
