# Hash-Subject

## Overview
**Hash-Subject** is a C++ implementation of a Hash Table designed for managing and organizing topics and titles. The project allows users to perform operations such as adding, deleting, and searching for topics, providing efficient and structured data handling.

## Features
- **Hash Table Implementation**:
  - A custom-built hash table for efficient data storage and retrieval.

- **Core Functionalities**:
  - Add topics and their associated titles.
  - Delete topics or titles from the hash table.
  - Search for specific topics and their details.

- **Performance**:
  - Optimized hashing mechanism for collision resolution.

- **Error Handling**:
  - Comprehensive handling for invalid inputs and missing data.

## Technologies Used
- **Language**: C++
- **Development Environment**: Visual Studio

## Installation and Setup
1. Clone the repository:
   ```bash
   git clone https://github.com/Noammandelbaum/Hash-Subject.git
   ```

2. Open the solution file (`HSubject.sln`) in Visual Studio.

3. Build the project by selecting **Build Solution** from the Build menu.

4. Run the application to interact with the hash table functionality.

## Usage
1. **Add Topics**:
   - Input a topic and its title to store them in the hash table.

2. **Delete Topics or Titles**:
   - Specify the topic or title you want to remove from the table.

3. **Search for Topics**:
   - Enter a topic name to retrieve its associated titles.

## File Structure
- `HSubject.cpp`: Main implementation of the hash table operations.
- `HSubject.h`: Header file defining the class structure.
- `HashTable.h`: Contains the hash table class and supporting methods.
- `main.cpp`: Entry point of the program, demonstrating the functionality.

## Example
```cpp
HashTable table;

// Adding topics and titles
table.addTopic("Programming", "C++");
table.addTopic("Science", "Physics");

// Searching for a topic
table.search("Programming");

// Deleting a topic
table.deleteTopic("Science");
```

## Contributions
Contributions are welcome! If you have ideas for improvement, feel free to fork the repository and submit a pull request.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

## Contact
For questions or feedback, please contact:
**Noam Mandelbaum**
- Email: [noam.mandelbaum@gmail.com](mailto:noam.mandelbaum@gmail.com)
- GitHub: [github.com/Noammandelbaum](https://github.com/Noammandelbaum)
