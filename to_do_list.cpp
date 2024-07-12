#include <bits/stdc++.h>
using namespace std;

struct ToDo
{
    string task;
    bool complete;
    struct ToDo *next;
};
typedef struct ToDo todo;

void task_input(todo *&head)
{
    system("cls");
    string taskinput;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "enter task:";
    getline(cin, taskinput);

    todo *newtask = new todo{taskinput, false, NULL};
    if (head == NULL)
        head = newtask;
    else
    {
        todo *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newtask;
    }
    system("cls");
}

void view_tasks(todo *head)
{
    system("cls");
    cout << "\n\n*******todo list*******\n\n";
    if (head == NULL)
    {
        cout << "empty todo list";
        return;
    }

    todo *ptr = head;
    int index = 1;
    while (ptr != NULL)
    {
        cout << index << "." << (*ptr).task << " ";
        if (ptr->complete == true)
            cout << "(completed)" << endl;
        else
            cout << "(uncompleted)" << endl;
        ptr = ptr->next;
        index++;
    }
}
void remove_task(todo *&head)
{
    system("cls");
    int index;
    cout << "Enter the task number you want to delete" << endl;
    cin >> index;
    if (index <= 0)
    {
        cout << "task not found";
        return;
    }
    if ((index == 1) && (head != NULL))
    {
        head = head->next;
        system("cls");
        cout << "cleared...";
        return;
    }
    if (head != NULL)
    {
        todo *previous = head;
        for (int i = 1; i <= (index - 2); i++)
        {
            previous = previous->next;
            if (previous->next == NULL)
            {
                cout << "task not found";
                return;
            }
        }
        if (previous->next == NULL)
        {
            cout << "task not found";
            return;
        }
        if (previous->next->next == NULL)
            previous->next = NULL;
        else
            previous->next = previous->next->next;
        system("cls");
        cout << "cleared...";
    }
    else
    {
        cout << "task not found";
        return;
    }
}
void mark_task_as_completed(todo *&head)
{
    system("cls");
    int index;
    cout << "Enter the task number you want to mark as completed" << endl;
    cin >> index;
    if ((index <= 0) || (head == NULL))
    {
        cout << "task not found";
        return;
    }
    if ((index == 1) && (head->complete == false))
    {
        head->complete = true;
        system("cls");
        cout << "done...";
        return;
    }
    else if ((index == 1) && (head->complete == true))
    {
        system("cls");
        cout << "it is already completed" << endl;
        return;
    }
    todo *ptr = head;
    for (int i = 1; i <= (index - 1); i++)
    {
        ptr = ptr->next;
        if (ptr == NULL)
        {
            cout << "task not found";
            return;
        }
    }
    if (ptr->complete == true)
    {
        system("cls");
        cout << "it is already completed" << endl;
        return;
    }
    else
    {
        ptr->complete = true;
        system("cls");
        cout << "done...";
    }
}
int main()
{
    system("cls");
    todo *head = NULL;
    int choice;
    while (1)
    {
        cout << "\n\n*******todo list*******\n\n"
             << "1.Add  a task to To-do list" << endl
             << "2.view To-do list" << endl
             << "3.Mark task as completed in To-do list" << endl
             << "4.Remove task from To-do list" << endl
             << "5.Exit the program" << endl
             << "enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            task_input(head);
            break;
        case 2:
            view_tasks(head);
            break;
        case 3:
            mark_task_as_completed(head);
            break;
        case 4:
            remove_task(head);
            break;
        case 5:
            system("cls");
            cout<<"Exiting...";
            return 0;
            break;
        default:
            system("cls");
            cout << "invalid input" << endl;
            break;
        }
    }
    return 0;
}