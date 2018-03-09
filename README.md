## C++ Address Book

### Functionality

*  Populate the data structure by parsing the supplied csv file.
*  Display entire address book on screen sorted by name.
*  Search for a contact by name. If a match exists, display name and phone number.
*  Delete a contact from the address book.
*  Data serialized to disk upon quitting and if available automatically loaded.

### Environment

Ubuntu 16.04

### Setup

Clone from [GitHub](https://github.com/MisterYu/gl_test).

Exectute `make all` in terminal to build `addess_book` executable.

### Running

Execute `make run` or `./address_book` to run executable.

If `address_book` will load `backup.txt` present otherwise, `data.csv` will be loaded.

##### `address_book` options

1. print all contacts.
2. find contact by name and print name and phone number.
3. find contact by name and delete.
0. quit and save modified contents to disk.

### Notes

The test code in this repo not working. Cases were devised. An attempt to integrate [Cpputest](https://github.com/cpputest/cpputest) was made but ultimately abandoned when compilation couldn't be achieved.
