# Inventory Management System

A console application in C++ for a grocery store to manage its products. Products are stored in a CSV file, so the data is kept between runs.

## Features

- **List** all products with their total price, total quantity and total stock value
- **Search** by ID, name, price or quantity
- **Add** a new product (duplicate IDs are rejected)
- **Delete** a product by ID
- **Save** changes to the CSV file, or save and exit

## Technologies

- C++ (STL: `vector`, `fstream`, `sstream`, `algorithm`)
- Object-oriented design: a `Product` struct with private fields, getters and setters
- File I/O with CSV parsing

## Project structure

| File | Description |
|------|-------------|
| `Product_Menegment.cpp` | Source code |
| `Product_Menegmant.csv` | Product database |
| `Product_Menegment.exe` | Compiled Windows build |

## Data format

Each line of the CSV file is one product:

```
ID,Name,Price,Quantity
```

Example: `1,Milk,5,20`

## How to run

The program uses `system("cls")`, so it is built for Windows.

```bash
g++ Product_Menegment.cpp -o Product_Menegment
./Product_Menegment
```

Keep `Product_Menegmant.csv` in the same folder as the program.

## Usage

1. Start the program and choose an option from the main menu (1-6).
2. When adding a product, enter: `ID Name Price Quantity` (for example `3 Bread 4 50`). Use one word for the name.
3. Choose **5** to save, or **6** to save and exit. Changes are lost if you close the program without saving.

## Possible improvements

- Edit existing products
- Input validation
- Support for names with spaces
- Cross-platform screen clearing

## Author

Temirlan Duishenbekov
GitHub: [Temirlan-Duishenbekov](https://github.com/Temirlan-Duishenbekov)
