#ifndef dk_tool_h
#define dk_tool_h
#define IG_SIZE 500



typedef struct tagBook
{
	char* author;
	char* title;
}book;

typedef struct tagShelf
{
	book *books;
	int aSize;
	int current_size;
}BookShelf;

BookShelf *createBookShelf (int aSize);
int addBook( BookShelf *aShelf, char* author, char* title );
void printBook(book *aBook);
void printBookShelf(BookShelf *aShelf);
//void bubbleSort(char *anArray);
//void selectionSort(char *anArray);
//void insertionSort(char *anArray);
void shallSort(BookShelf *aShelf);
int binarySearch(BookShelf *aShelf, char Value, int aSize);



#endif
