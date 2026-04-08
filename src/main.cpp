#include <iostream> 
#include "node.h"
#include "queue.h"

/** 
 * @file 
 * @brief The complete program of the dynamic queue.
 * Includes a menu function so that the user may input any desired value.
 *
 * @details The options are as followed:
 * - Option 1 allows the user to input any value of type int.
 * - Option 2 allows the user to delete the Node at the front of the queue.
 * - Option 3 allows the user to view the value at the front of the queue.
 * - Option 5 allows the user to view all the Nodes of the queue, as well as the first and last elements.
 * - Option 5 allows the user to exit the program.
 */

int menu();
using namespace std;

int main()
{
    Queue<int> queue; ///< Initializes a stack of type int.

    while (true)
	{

		switch (menu())
		{
		case 1:
        {
            int value;
			cout << "\nWhat value is to be stored in the new Node?: ";
            cin >> value;

            queue.enqueue(new Node<int>(value));
            cout << "\nThe node has been added with the value of " << value << "!";
			break;
        }
		case 2:
        {
            try ///< Attempts to delete the front of the queue.
            {
                cout << "\nThe value stored in the front of the queue is: " << queue.dequeue();
                cout << "\nThe front of the queue has been deleted!";
            }
            catch(const std::exception& e) ///< Sends a message if an error occurs.
            {
                std::cerr << e.what() << '\n';
            }

            break;
        }
        case 3:
        {
            try ///< Attempts to retrieve the value in front of the queue.
            {
                cout << "\nThe value stored in the front of the queue is: " << queue.peek();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n'; ///< Sends a message if an error occurs.
            }

            break;
        }
        case 4:
        {
            queue.display();
            break;  
        }
        case 5:
        {
			cout << "\nExiting the program...";
			exit(0);
			break;
        }
        }
    }
}

/***********************************************************************/

/** 
 * @brief Menu that manages user input.
 *
 * @details Returns an option to the main function.
 */

int menu()
{
    int option;
	do
	{
		cout << "\n\n\n\t--- MENU! ---";
		cout << "\n1) Push.\n";
		cout << "2) Pop.\n";
		cout << "3) Peek.\n";
		cout << "4) Display.\n";
        cout << "5) Exit.\n";
		cout << "\n--> Choose an option: ";
		cin >> option;
	} while (option < 1 || option > 5);
	return option;
}

/***********************************************************************/

/** 
 * @page Tests
 * @brief Execution of the Queue program.
 * @section queue_test Test results
 * 
 * The following images show the execution of the Queue program in the terminal,
 * including the functions of Enqueue, Dequeue, Peek and Display.
 * 
 * \image latex qTest1.png "Queue execution! (Part 1)"
 * \image html qTest1.png
 * 
 * \image latex qTest2.png "Queue execution! (Part 2)"
 * \image html qTest2.png
 * 
 * \image latex qTest3.png "Queue execution! (Part 3)"
 * \image html qTest3.png
 */
