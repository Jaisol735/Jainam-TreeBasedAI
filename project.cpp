#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <variant>
#include <cctype>
#include <unordered_set>
#include <functional>
#include <cmath>
using namespace std;
struct Leaf
{
    string data;
    Leaf* l1;
    Leaf* l2;
    Leaf* l3;
    Leaf* l4;
    function<void()> func;
    string value;
    string explanation;
    char q;
    int r;
    float s;

    Leaf() : func(nullptr), l1(nullptr), l2(nullptr), l3(nullptr), l4(nullptr), value("null"), explanation("null"), q('n'), r(0), s(0.0f) {}
};
class tree
{
    Leaf* Root;
public:
    tree()
    {
        Root = new Leaf();
        Root->data = "\nHow can I help you, Sir?";
    }

    void start()
    {
        Leaf* Mood = new Leaf();
        Leaf* Problem = new Leaf();
        Leaf* conversation = new Leaf();
        Root->l1 = Problem;
        Root->l2 = Mood;
        Root->l3 = conversation;
        string i1;
        cout << "Enter the command sir" << endl;
        cin >> ws;
        getline(cin, i1);
        unordered_set<string> d = { "I have a problem", "I have a good day", "I have a bad day", "I don't know what to do" };
        Root->value = correctInput(i1, d);
        if (Root->value == "I have a problem")
        {
            handleProblem(Problem);
        } else if (Root->value == "I have a good day" || Root->value == "I have a bad day")
        {
            handleMood(Mood);
        } else
        {
            handleconversation(conversation);
        }
    }
    void handleProblem(Leaf* Problem)
    {
        Leaf* Education = new Leaf();
        Leaf* Maths = new Leaf();
        Leaf* Preparation = new Leaf();
        Problem->l1 = Education;
        Problem->l2 = Maths;
        Problem->l3 = Preparation;
        Problem->data = "\nWhat happened, sir?";
        cout << Problem->data << endl;
        string i1;
        cin >> ws;
        getline(cin, i1);
        unordered_set<string> problem_options = { "I need help in my homework", "I need help in calculation", "My exams are near" };
        Problem->value = correctInput(i1, problem_options);

        if (Problem->value == "I need help in my homework")
        {
            handleEducation(Education, Problem);
        } else if (Problem->value == "I need help in calculation")
        {
            handleMaths(Maths, Problem);
        } else if (Problem->value == "My exams are near")
        {
            cout << "Stay calm, let's prepare for your exams!" << endl;
            handlePreparation(Preparation, Problem);
        }
    }
    void handleEducation(Leaf* Education, Leaf* Problem)
    {
        Leaf* Theory = new Leaf();
        Leaf* Codes = new Leaf();
        Leaf* Graphs = new Leaf();
        Education->l1 = Theory;
        Education->l2 = Codes;
        Education->l3 = Graphs;
        Education->data = "Let's work on your homework. In what subject do you need help, sir?";
        cout << Education->data << endl;
        string i1;
        cin >> ws;
        getline(cin, i1);
        unordered_set<string> education_options = { "I want help in theory", "I want help in codes", "I want help in graphs" };
        Education->value = correctInput(i1, education_options);
        if (Education->value == "I want help in theory")
        {
            Theory->data = "\n What do you want to know?";
            cout << Theory->data << endl;
            Theory->func = [this]() { this->GoogleSearch(); };
            Theory->func();
        } else if (Education->value == "I want help in codes")
        {
            handleCodes(Codes,Education,Problem);
        } else if (Education->value == "I want help in graphs")
        {
            handleGraphs(Graphs,Education,Problem);
        } else
        {
            return;
        }
    }
    void handleCodes(Leaf* Codes,Leaf* Education, Leaf* Problem)
    {
        Leaf* Stackk = new Leaf();
        Leaf* Queuee = new Leaf();
        Leaf* Linklistt = new Leaf();
        Leaf* BST = new Leaf();
        Codes->l1 = Stackk;
        Codes->l2 = Queuee;
        Codes->l3 = Linklistt;
        Codes->l4 = BST;
        Codes->data="Which code do you want to know(1: Stack,2: Circular Queue,3: Linklist,4: Binary search tree)";
        cout<<Codes->data<<endl;
        cin>>Codes->r;
        int choice = Codes->r;
        switch (choice)
        {
            case 1:
                Stackk->explanation="A Stack is a linear data structure that follows the Last In, First Out (LIFO) principle, meaning the last element added is the first one to be removed. It supports two primary operations: push (to add an element) and pop (to remove the top element). Stacks are often used in scenarios such as function call management (call stack), expression evaluation, and backtracking algorithms. Stacks can be implemented using arrays or linked lists.";
                cout<<Stackk->explanation<<endl;
                stackk();
                break;
            case 2:
                Queuee->explanation = "A Circular Queue is a linear data structure that uses a fixed-size array and connects the last position back to the first position to create a circular structure. This means that once the end of the queue is reached, it wraps around to the beginning. It efficiently utilizes space by allowing elements to be added and removed in O(1) time while maintaining a continuous flow of elements. It is commonly used in applications such as round-robin scheduling and buffering.";
                cout<<Queuee->explanation<<endl;
                queuee();
                break;
            case 3:
                Linklistt->explanation = "A Doubly Linked List is a linear data structure where each node contains a value, a pointer to the next node, and a pointer to the previous node. This structure allows traversal in both directions (forward and backward). Operations like insertion and deletion are efficient, as they can be performed in O(1) time when the node to be altered is known. However, it requires more memory than a singly linked list due to the additional pointer for the previous node.";
                cout<<Linklistt->explanation<<endl;
                linklist();
                break;
            case 4:
                BST->explanation = "A Binary Search Tree (BST) is a hierarchical data structure where each node contains a value, along with pointers to its left and right children. In a BST, the left child's value is always less than the parent node's value, while the right child's value is greater. This property allows for efficient searching, insertion, and deletion operations, typically with a time complexity of O(log n) for balanced trees. BSTs facilitate ordered traversal, enabling operations such as in-order, pre-order, and post-order traversals to retrieve sorted data.";
                cout<<BST->explanation<<endl;
                binarysearchtree();
                break;
            default:
                cout << "Invalid choice. Exiting." << endl;
                break;
        }
    }
    void queuee()
    {
        class Queue
        {
            int size;
            int Rear,Front;
            int* a;
        public:
            Queue ()
            {
                Rear=-1;
                Front=-1;
                cout<<"\n Enter the size of array";
                cin>>size;
                a = new int[size];
            }
            int check()
            {
                if (Rear == size-1)
                {
                    if (Front!=0)
                    {
                        circularqueue();
                        return 1;
                    }else
                    {
                        return 0;
                    }
                }else
                {
                    return 1;
                }
            }
            void input ()
            {
                int k;
                k=check();
                if (k==0)
                {
                    cout<<"\n Queue is full";
                }else
                {
                    int i;
                    cout<<"\n Enter the input:";
                    cin>>i;
                    Rear++;
                    a[Rear]=i;
                    if (Rear==0)
                    {
                        Front++;
                    }
                }
            }
            void pop ()
            {
                if ((Rear==-1)||(Front>Rear))
                {
                    cout<<"\n Queue is empty";
                }else
                {
                    int s;
                    s=a[Front];
                    Front++;
                    cout<<"\n Removed from Queue"<<s;
                }
            }
            void circularqueue()
            {
                int p=Front;
                int n = 0;
                int m = Front+1;
                do
                {
                    a[n]=a[p];
                    n++;
                    p++;
                    Front++;
                }while(Front<=Rear);
                Rear = size - m;
                Front = 0;
                cout<<"\n Circular queue task done";
            }
            void display()
            {
                int o;
                if ((Rear==-1)||(Front>Rear))
                {
                    cout<<"\n Queue is empty";
                }else
                {
                    for(o=Front;o<=Rear;o++)
                    {
                        cout<<a[o]<<" ";
                    }
                }
            }
        };
        Queue s1;
        int choice;
        cout<<"\nEnter Choice:(check - 2,input - 1,pop - 3,display - 4,Exit - 5) ";
        cin>>choice;
        while (choice!=5)
        {
            if(choice == 2)
            {
                s1.check();
            }else if(choice == 1)
            {
                s1.input();
            }else if(choice == 3)
            {
                s1.pop();
            }else if(choice == 4)
            {
                s1.display();
            }
            cout<<"\nEnter Choice:(check - 1,input - 2,pop - 3,display - 4,Exit - 5) ";cin>>choice;
        }
    }
    void stackk()
    {
        class Stack
        {
            int size;
            int top;
            int* a;
        public:
            Stack ()
            {
                top=-1;
                cout<<"\n Enter the size of array";
                cin>>size;
                a = new int[size];
            }
            int overflow ()
            {
                if(top==(size-1))
                {
                    return 1;
                }else
                {
                    return 0;
                }
            }
            int underflow ()
            {
                if(top==-1)
                {
                    return 1;
                }else
                {
                    return 0;
                }
            }
            void push ()
            {
                int k;
                k=overflow ();
                if(k==1)
                {
                    cout<<"\nStack is Full. ";
                }else
                {
                    top=top+1;
                    cout<<"\nEnter Element: ";cin>>a[top];
                 }
            }
            void pop ()
            {
                int k,item;
                k=underflow ();
                if(k==1)
                {
                    cout<<"\nStack is Empty. ";
                }else
                {
                    item=a[top];
                    cout<<"\nItem deleted is : "<<item;
                    top=top-1;
                }
            }
            void peep ()
            {
                if(top==-1)
                {
                    cout<<"\nStack is Empty. ";
                }else
                {
                    cout<<"\nTop Element is: "<<a[top];
                    cout<<"\nTop is: "<<top;
                }
            }
        };
        Stack s1;
        int choice;
        cout<<"\nEnter Choice:(Push - 1,Pop - 2,Peep - 3,Exit - 4) ";cin>>choice;
        while (choice !=4)
        {
            if(choice == 1)
            {
                s1.push();
            }else if(choice == 2)
            {
                s1.pop();
            }else if(choice == 3)
            {
                s1.peep();
            }
            cout<<"\nEnter Choice:(Push - 1,Pop - 2,Peep - 3,Exit - 4) ";cin>>choice;
        }
    }
    void binarysearchtree()
    {
        struct bLeaf
        {
            int data;
            bLeaf* Left;
            bLeaf* Right;
            bLeaf* prev;
        };
        class btree
        {
            bLeaf* bRoot;
        public:
            btree()
            {
                bRoot = nullptr;
            }
            void bInsert()
            {
                int x,j=0;
                char l,m;
                cout<<"\n Enter the element to input";
                cin>>x;
                bLeaf* newbLeaf = new bLeaf();
                newbLeaf->data = x;
                newbLeaf->Left = nullptr;
                newbLeaf->Right = nullptr;
                newbLeaf->prev = nullptr;
                if(bRoot == nullptr)
                {
                    bRoot = newbLeaf;
                }else
                {
                    bLeaf* Move = bRoot;
                    while(j==0)
                    {
                        if(newbLeaf->data<Move->data)
                        {
                            if(Move->Left == nullptr)
                            {
                                Move->Left=newbLeaf;
                                newbLeaf->prev=Move;
                                Move = newbLeaf;
                                break;
                            }else
                            {
                                Move = Move->Left;
                                continue;
                            }
                         }else
                          {
                                if(Move->Right==nullptr)
                                {
                                    Move->Right=newbLeaf;
                                    newbLeaf->prev=Move;
                                    Move = newbLeaf;
                                    break;
                                }else
                                {
                                    Move = Move->Right;
                                    continue;
                                }
                          }
                    }
                }
            }
            void preorderTraversal(bLeaf* temp)
            {
                if (temp == nullptr)
                    return;
                cout<<temp->data << " ";
                preorderTraversal(temp->Left);
                preorderTraversal(temp->Right);
            }
            void inorderTraversal(bLeaf* temp)
            {
                if (temp == nullptr)
                    return;
                inorderTraversal(temp->Left);
                cout<<temp->data << " ";
                inorderTraversal(temp->Right);
            }
            void postorderTraversal(bLeaf* temp)
            {
                if (temp == nullptr)
                    return;
                postorderTraversal(temp->Left);
                postorderTraversal(temp->Right);
                cout<<temp->data << " ";
            }
            void bDisplay()
            {
                int l;
                cout<<"\n Which display method you want(preorder-1 or inorder or postorder - 3)";
                cin>>l;
                if(l==1)
                {
                    preorderTraversal(bRoot);
                }else if(l==2)
                {
                    inorderTraversal(bRoot);
                }else
                {
                    postorderTraversal(bRoot);
                }
            }
        };
        btree a;
        int i;
        cout<<"\n What you have to do(Insert - 1 or Display - 2 or Exit - 3)";
        cin>>i;
        while(i!=3)
        {
            if(i==1)
            {
                a.bInsert();
            }
            else if(i==2)
            {
                a.bDisplay();
            }
            cout<<"\n What you have to do(Insert - 1 or Display - 2 or Exit - 3)";
            cin>>i;
        }
    }
    void linklist()
    {
        struct Node
        {
            int data;
            Node* next;
            Node* prev;
        };
        class linked
        {
            Node *Start, *End, *Move;
        public:
            linked()
            {
                Start = nullptr;
                End = nullptr;
                Move = nullptr;
            }
            void add()
            {
                int x;
                cout << "\nEnter the value to add to the list: ";
                cin >> x;
                Node* newNode = new Node();
                newNode->data = x;
                newNode->next = nullptr;
                newNode->prev = nullptr;
                if (Start == nullptr)
                {
                    Start = newNode;
                    End = newNode;
                } else
                {
                    End->next = newNode;
                    newNode->prev = End;
                    End = newNode;
                }
            }
            void insertt()
            {
                int i1, i2, q, r;
                Move = Start;
                cout << "\nEnter the value to insert in the list: ";
                cin >> i1;
                cout << "\nEnter the choice: 1. Insert at start, 2. Insert at end, 3. Insert in between: ";
                cin >> i2;
                Node* newNode = new Node();
                newNode->data = i1;
                newNode->next = nullptr;
                newNode->prev = nullptr;
                if(Start==nullptr)
                {
                    Start = newNode;
                    End = newNode;
                    return;
                }
                switch (i2)
                {
                    case 1:
                        Start->prev = newNode;
                        newNode->next = Start;
                        Start = newNode;
                        break;
                    case 2:
                        End->next = newNode;
                        newNode->prev = End;
                        End = newNode;
                        break;
                    case 3:
                        cout << "\nEnter the value before which to insert in the list: ";
                        cin >> q;
                        cout << "\nEnter the value after which to insert in the list: ";
                        cin >> r;
                        while (Move != nullptr) {
                            if (Move->data == q && Move->next != nullptr && Move->next->data == r)
                            {
                                newNode->next = Move->next;
                                newNode->prev = Move;
                                Move->next->prev = newNode;
                                Move->next = newNode;
                                break;
                            } else
                            {
                                Move = Move->next;
                            }
                        }
                        break;
                }
            }
            void pop()
            {
                int d1,d2;
                if (Start == nullptr)
                {
                    cout << "\nList is empty, nothing to delete." << endl;
                    return;
                }
                if(Start==End)
                {
                    Node* t = Start;
                    Start = nullptr;
                    End = nullptr;
                    delete(t);
                }
                Move = Start;
                cout << "\nEnter the choice: 1. Delete at start, 2. Delete at end, 3. Delete in between: ";
                cin >> d2;
                Node* t = nullptr;
                switch (d2)
                {
                    case 1:
                        t = Start;
                        Start = Start->next;
                        Start->prev=nullptr;
                        delete(t);
                        break;
                    case 2:
                        t = End;
                        End=End->prev;
                        End->next=nullptr;
                        delete(t);
                        break;
                    case 3:
                        cout << "\nEnter the value to delete in the list: ";
                        cin >> d1;
                        while (Move != nullptr)
                        {
                            if (Move->next->data == d1 && Move->next != nullptr && Move->next->next != nullptr )
                            {
                                t = Move->next;
                                Move->next=Move->next->next;
                                Move->next->next->prev = Move;
                                delete(t);
                                break;
                            }else
                            {
                                Move = Move->next;
                            }
                        }
                        if (Move==nullptr)
                        {
                            cout<<"Element not found";
                        }
                        break;
                    }
             }
             void Replace()
             {
                 int b, c;
                 cout << "\nEnter the value to replace in the list: ";
                 cin >> c;
                 cout << "\nEnter the new value: ";
                 cin >> b;
                 Move = Start;
                 while (Move != nullptr)
                {
                    if (Move->data == c)
                    {
                        Move->data = b;
                        break;
                    }
                    Move = Move->next;
                 }
                 if (Move == nullptr)
                 {
                    cout << "\nElement was not found in the list" << endl;
                 }
             }
              void display()
              {
                  int s1;
                  cout<<"\n Display Start to end = 1 else display End to Start = 0: ";
                  cin>>s1;
                  Move = Start;
                  Node* temp = End;
                  if (Start == nullptr)
                  {
                     cout << "\nList is empty." << endl;
                     return;
                   }
                   if(s1==1)
                   {
                      while (Move != nullptr)
                      {
                            cout << Move->data << " ";
                            Move = Move->next;
                      }
                   }else if (s1==0)
                   {
                      while (temp != nullptr)
                      {
                            cout << temp->data << " ";
                            temp = temp->prev;
                      }
                   }
              }
        };
        linked n;
        int choice;
        cout << "\nEnter Choice: (add - 1, insertt - 2, pop - 3, Replace - 4, display - 5, Exit - 6) ";
        cin >> choice;
        while (choice !=5)
        {
            if (choice == 1)
            {
                n.add();
            } else if (choice == 2)
            {
                n.insertt();
            } else if (choice == 3)
            {
                n.pop();
            } else if (choice == 4)
            {
                n.Replace();
            } else if (choice == 5)
            {
                n.display();
            }
            cout << "\nEnter Choice: (add - 1, insertt - 2, pop - 3, Replace - 4, display - 5, Exit - 6) ";
            cin >> choice;
        }
    }
    void handleGraphs(Leaf* Graphs,Leaf* Education, Leaf* Problem)
    {
        Leaf* Line = new Leaf();
        Leaf* Dot = new Leaf();
        Leaf* Bar = new Leaf();
        Graphs->l1 = Line;
        Graphs->l2 = Dot;
        Graphs->l3 = Bar;
        int n;
        cout << "Enter the number of data points: ";
        cin >> n;
        vector<int> data(n);
        cout << "Enter the data points (positive integers): " << endl;
        for (int i = 0; i < n; ++i)
        {
            cin >> data[i];
        }
        Graphs->data="Which Graph do you want to draw(1: Line,2: Dot,3: Bar)";
        cout<<Graphs->data<<endl;
        cin>>Graphs->r;
        switch(Graphs->r)
        {
        case 1:
            Line->explanation = "Generating the graph";
            cout<<Line->explanation;
            line(data);
        case 2:
            Dot->explanation = "Generating the graph";
            cout<<Dot->explanation;
            dot(data);
        case 3:
            Bar->explanation = "Generating the graph";
            cout<<Bar->explanation;
            bar(data);
        default:
            cout<<"\n Invalid input";
        }
    }
    void line(const vector<int>& data)
    {
        cout << "Line Graph:" << endl;
        int maxValue = *max_element(data.begin(), data.end());
        for (int y = maxValue; y > 0; --y)
        {
            cout << setw(2) << y << "| ";
            for (int i = 0; i < data.size(); ++i)
            {
                if (data[i] >= y)
                {
                    cout << "- ";
                } else
                {
                    cout << "  ";
                }
        }
        cout << endl;
        }
        cout << "   ";
        for (int i = 1; i <= data.size(); ++i)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    void dot(const vector<int>& data)
    {
        cout << "Dot Graph:" << endl;
        int maxValue = *max_element(data.begin(), data.end());
        for (int y = maxValue; y > 0; --y)
        {
            cout << setw(2) << y << "| ";
            for (int i = 0; i < data.size(); ++i)
            {
                if (data[i] >= y)
                {
                    cout << ". ";
                } else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
        cout << "   ";
        for (int i = 1; i <= data.size(); ++i)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    void bar(const vector<int>& data)
    {
        cout << "Bar Graph:" << endl;
        int maxValue = *max_element(data.begin(), data.end());
        for (int y = maxValue; y > 0; --y)
        {
            cout << setw(2) << y << "| ";
            for (const auto& value : data)
            {
                if (value >= y)
                {
                    cout << "# ";
                } else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
        cout << "   ";
        for (int i = 1; i <= data.size(); ++i)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    void handleMaths(Leaf* Maths, Leaf* Problem)
    {
        Leaf* Normalcal = new Leaf();
        Leaf* Factorization = new Leaf();
        Leaf* Search = new Leaf();
        Maths->l1 = Normalcal;
        Maths->l2 = Factorization;
        Maths->l3 = Search;
        Maths->data = "What Calculation you want to do";
        cout << Maths->data << endl;
        string i1;
        cin >> ws;
        getline(cin, i1);
        unordered_set<string> Calculation_options = { "Normal calculation", "Factorization", "Other maths problem" };
        Maths->value = correctInput(i1, Calculation_options);
        if (Maths->value == "Normal Calculation")
        {
            handleNormalcal(Normalcal,Maths,Problem);
        }else if (Maths->value == "Factorization")
        {
            handleFactorization(Factorization,Maths,Problem);
        }else
        {
            Search->func = [this]() { this->GoogleSearch(); };
            Search->func();
        }
    }
    void handleNormalcal(Leaf* Normalcal, Leaf* Maths, Leaf* Problem)
    {
        Normalcal->func = [this]() { this->evaluateExpression(); };
        Normalcal->func();
    }
    void handleFactorization(Leaf* Factorization, Leaf* Maths, Leaf* Problem)
    {
        Factorization->func = [this]() { this->factorizeEquation(); };
        Factorization->func();
    }
    void handlePreparation(Leaf* Preparation,Leaf*  Problem)
    {
        Preparation->explanation = "Sir as per your grasping the knowledge is very good you can easily crack then exam. Only you have to study 3 hours a day if exams are in 2 day you should study for 4 hours";
        cout<<Preparation->explanation<<endl;
        cout<<"\n Do you want to see any reference video(yes or no)";
        cin>>Preparation->value;
        if(Preparation->value == "yes")
        {
            Preparation->func = [this]() { this->GoogleSearch(); };
            Preparation->func();
        }else
        {
            cout<<"\n For any help I am here sir";
            return;
        }
    }
    void handleMood(Leaf* Mood)
    {
        if (Root->value == "I have a good day")
        {
            Mood->data = "That's great to hear!";
            cout<< Mood->data<< endl;
            char g;
            cout<<"\n Do you want to play a game or listen music(play game - p or listen music - m)";
            cin>>g;
            if(g=='p')
            {
                Mood->value = "Let's start the game";
                int choice;
                cout<<"\n Which Game do you want to play(1. Tic-Tac-Toe,2. Rock, Paper, Scissors,3. Minesweeper,4. Snake Game,5. Exit)";
                cin >> choice;
                Mood->r = choice;
                switch (Mood->r)
                {
                    case 1:
                        Mood->func = [this]() { this->playTicTacToe(); };
                        Mood->func();
                        break;
                    case 2:
                        Mood->func = [this]() { this->playRockPaperScissors(); };
                        Mood->func();
                        break;
                    case 3:
                        Mood->func = [this]() { this->playMinesweeper(); };
                        Mood->func();
                        break;
                    case 4:
                        Mood->func = [this]() { this->playSnakeGame(); };
                        Mood->func();
                        break;
                    case 5:
                        cout << "Exiting the game. Goodbye!" << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please select a number between 1 and 5." << endl;
               }
            }else if (g=='m')
            {
                Mood->func = [this]() { this->PlayMusic(); };
                Mood->func();
            }else
            {
                return;
            }
        } else
        {
            Mood->data = "Sir I think you should listen some music";
            cout << Mood->data << endl;
            Mood->func = [this]() { this->PlayMusic(); };
            Mood->func();
        }
    }
    void handleconversation(Leaf* conversation)
    {
        char i2;
        Leaf* Info = new Leaf();
        Leaf* Play = new Leaf();
        conversation->l1 = Info;
        conversation->l2 = Play;
        conversation->value = schedule();
        if (conversation->value == "Sir you are in the class pls focus")
        {
            cout<<conversation->value<<endl;
            cout<<"Do you want some information(yes - y or no-n)";
            cin>>i2;
            if (i2 == 'y')
            {
                Info->func = [this]() { this->GoogleSearch(); };
                Info->func();
                return;
            }
            else
            {
                return;
            }
        }
        else if (conversation->value == "Sir it's your free time")
        {
            cout<<"Do you want some information(yes - y or no-n)";
            cin>>i2;
            if (i2 == 'y')
            {
                Info->func = [this]() { this->GoogleSearch(); };
                Info->func();
            }
            else
            {
                Play->value = "Let's start the game";
                int choice;
                cout<<"\n Which Game do you want to play(1. Tic-Tac-Toe,2. Rock, Paper, Scissors,3. Minesweeper,4. Snake Game,5. Exit)";
                cin >> choice;
                Play->r = choice;
                switch (Play->r)
                {
                    case 1:
                        Play->func = [this]() { this->playTicTacToe(); };
                        Play->func();
                        break;
                    case 2:
                        Play->func = [this]() { this->playRockPaperScissors(); };
                        Play->func();
                        break;
                    case 3:
                        Play->func = [this]() { this->playMinesweeper(); };
                        Play->func();
                        break;
                    case 4:
                        Play->func = [this]() { this->playSnakeGame(); };
                        Play->func();
                        break;
                    case 5:
                        cout << "Exiting the game. Goodbye!" << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please select a number between 1 and 5." << endl;
               }
            }
        }else
        {
            Info->func = [this]() { this->GoogleSearch(); };
            Info->func();
        }
    }
    void deleteall(Leaf* temp)
    {
        if (temp == nullptr)
        {
            return;
        }
        deleteall(temp->l1);
        deleteall(temp->l2);
        deleteall(temp->l3);
        delete temp;
    }
    void Delete(char y)
    {
        if(y == 'y')
        {
            deleteall(Root);
        }else
        {
            deleteall(Root);
            delete(Root);
        }
    }
    void greet()
    {
        auto start_time = chrono::steady_clock::now();
        int Count = 0;
        while (Count<1)
        {
            time_t now = time(0);
            tm* ltm = localtime(&now);
            int hour = ltm->tm_hour;
            if (hour >= 5 && hour < 12)
            {
                cout << "Good Morning Sir" << endl;
            } else if (hour >= 12 && hour < 17)
            {
                cout << "Good Afternoon Sir" << endl;
            } else if (hour >= 17 && hour < 21)
            {
                cout << "Good Evening Sir" << endl;
            } else
            {
                cout << "Good Night Sir" << endl;
            }
            cout << "Current time: " << put_time(ltm, "%H:%M:%S") << endl;
            auto current_time = chrono::steady_clock::now();
            chrono::duration<double> elapsed_seconds = current_time - start_time;
            int max_min = elapsed_seconds.count() / 60;
            int max_hr = max_min / 60;
            if (max_hr >= 1) {
                cout << "Take a rest, sir! You've been running this for " << max_hr << " hours." << endl;
                start_time = chrono::steady_clock::now();
            }
            Count++;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    string schedule()
    {
        auto start_time = chrono::steady_clock::now();
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int hour = ltm->tm_hour;
        if (hour >= 8 && hour < 14)
        {
            return "Sir you are in the class pls focus";
        } else if (hour >= 14 && hour < 17)
        {
            return "Sir it's your free time";
        } else if (hour >= 17 && hour < 20)
        {
            return "You should study sir";
        } else if (hour >= 20 && hour < 23)
        {
            return "Sir it's your free time";
        }
        else
        {
            return "You should sleep sir";
        }
    }
    void evaluateExpression()
    {
        string input;
        cout << "Enter a mathematical expression: ";
        getline(cin, input);
        input.erase(remove(input.begin(), input.end(), ' '), input.end());
        auto evaluateSimple = [](string expr)
        {
            int result = 0;
            char op = '+';
            int number = 0;
            for (size_t i = 0; i < expr.length(); i++)
            {
                if (isdigit(expr[i]))
                {
                    number = 0;
                    while (i < expr.length() && isdigit(expr[i]))
                    {
                        number = number * 10 + (expr[i] - '0');
                        i++;
                    }
                    i--;
                    if (op == '+') result += number;
                    else if (op == '-') result -= number;
                    else if (op == '*') result *= number;
                    else if (op == '/') result /= number;
                } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
                {
                    op = expr[i];
                }
            }
           return result;
        };
        function<int(string)> evaluate = [&](string expr) -> int
        {
            size_t pos = 0;
            while ((pos = expr.find('(')) != string::npos)
            {
                size_t endPos = expr.find(')', pos);
                if (endPos == string::npos)
                {
                    cerr << "Mismatched parentheses!" << endl;
                    exit(1);
                }
                string subExpr = expr.substr(pos + 1, endPos - pos - 1);
                int subResult = evaluate(subExpr);
                expr.replace(pos, endPos - pos + 1, to_string(subResult));
            }
            return evaluateSimple(expr);
        };
        int result = evaluate(input);
        cout << "Result: " << result << endl;
    }
    void factorizeEquation()
    {
        int a, b, c;
        cout << "Enter the coefficients of the quadratic equation (ax^2 + bx + c = 0):\n";
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        cout << "c: ";
        cin >> c;
        int discriminant = b * b - 4 * a * c;
        int sqrtDiscriminant = sqrt(discriminant);
        if (discriminant < 0)
        {
            cout << "The equation has complex roots. Cannot factorize using real numbers.\n";
        } else if (sqrtDiscriminant * sqrtDiscriminant != discriminant)
        {
            cout << "The equation does not have real factorization with integers.\n";
        } else
        {
            int x1 = (-b + sqrtDiscriminant) / (2 * a);
            int x2 = (-b - sqrtDiscriminant) / (2 * a);
            cout << "The factorized form of the equation is:\n";
            if (x1 == x2)
            {
                cout << a << "(x - " << x1 << ")^2 = 0" << endl;
            } else
            {
                cout << a << "(x - " << x1 << ")(x - " << x2 << ") = 0" << endl;
            }
        }
    }
    void GoogleSearch()
    {
        string query;
        cout << "Enter your search query: ";
        getline(cin, query);
        replace(query.begin(), query.end(), ' ', '+');
        string url = "start https://www.google.com/search?q=" + query;
        system(url.c_str());
    }
    string correctInput(const string& input, const unordered_set<string>& dictionary)
    {
        if (dictionary.find(input) == dictionary.end()) {
            cout << "Did you mean: ";
            bool first = true;
            for (const auto& command : dictionary) {
                if (command.find(input) != string::npos) {
                    if (!first) cout << ", ";
                    cout << command;
                    first = false;
                }
            }
            cout << "?" << endl;
            return input;
        }
        return input;
    }
    void PlayMusic()
    {
        string spotifyPlaylist = "https://open.spotify.com/playlist/5yTJ5bA1O0MxOvWapkfRTh?si=9ed23f3c8b57465c";
        string command = "start " + spotifyPlaylist;
        system(command.c_str());
        cout << "Opening your Spotify playlist..." << endl;
    }
    void playTicTacToe()
    {
        char board[3][3] = {{'1', '2', '3'},
                           {'4', '5', '6'},
                           {'7', '8', '9'}};
        int player = 1;
        int choice;
        int row, col;
        while (true)
        {
            cout << "Player 1 [X] - Player 2 [O]" << endl;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
            cout << "Player " << player << ", enter a number: ";
            cin >> choice;
            switch (choice)
            {
                case 1: row = 0; col = 0; break;
                case 2: row = 0; col = 1; break;
                case 3: row = 0; col = 2; break;
                case 4: row = 1; col = 0; break;
                case 5: row = 1; col = 1; break;
                case 6: row = 1; col = 2; break;
                case 7: row = 2; col = 0; break;
                case 8: row = 2; col = 1; break;
                case 9: row = 2; col = 2; break;
                default:
                    cout << "Invalid choice! Try again." << endl;
                    continue;
             }
             if (board[row][col] == 'X' || board[row][col] == 'O')
             {
                cout << "Cell already occupied! Try again." << endl;
                continue;
             }
             board[row][col] = (player == 1) ? 'X' : 'O';
             for (int i = 0; i < 3; i++)
             {
                 if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||(board[0][i] == board[1][i] && board[1][i] == board[2][i]))
                {
                    cout << "Player " << player << " wins!" << endl;
                    return;
                }
             }
             if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
             {
                cout << "Player " << player << " wins!" << endl;
                return;
             }
             bool draw = true;
             for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (board[i][j] != 'X' && board[i][j] != 'O')
                        draw = false;

             if (draw)
            {
                cout << "It's a draw!" << endl;
                return;
            }
             player = (player % 2) + 1;
        }
    }
    void playRockPaperScissors()
    {
        int playerChoice, computerChoice;
        srand(time(0));
        cout << "Rock, Paper, Scissors!" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> playerChoice;
        computerChoice = rand() % 3 + 1;
        cout << "Computer chose: " << computerChoice << endl;
        if (playerChoice == computerChoice)
        {
            cout << "It's a tie!" << endl;
        } else if ((playerChoice == 1 && computerChoice == 3) || (playerChoice == 2 && computerChoice == 1) ||(playerChoice == 3 && computerChoice == 2))
        {
            cout << "You win!" << endl;
        } else
        {
            cout << "You lose!" << endl;
        }
    }
    void playMinesweeper()
    {
        const int SIZE = 5;
        const int MINES = 3;
        vector<vector<char>> board(SIZE, vector<char>(SIZE, '*'));
        vector<vector<bool>> revealed(SIZE, vector<bool>(SIZE, false));
        int mineCount = 0;
        srand(time(0));
        while (mineCount < MINES)
        {
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            if (board[row][col] != 'M')
            {
                board[row][col] = 'M';
                mineCount++;
            }
        }
        while (true)
        {
            cout << "Minesweeper Board:\n";
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    if (revealed[i][j])
                    {
                        cout << board[i][j] << " ";
                    } else
                    {
                        cout << "* ";
                    }
                }
                cout << endl;
            }
            int x, y;
            cout << "Enter coordinates (row and column): ";
            cin >> x >> y;
            if (board[x][y] == 'M')
            {
                cout << "Game Over! You hit a mine!" << endl;
                break;
            } else
            {
                revealed[x][y] = true;
            }
            bool win = true;
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    if (board[i][j] == 'M' && !revealed[i][j])
                    {
                        win = false;
                    }
                }
            }
            if (win)
            {
                cout << "Congratulations! You've cleared the mines!" << endl;
                break;
            }
        }
    }
    void playSnakeGame()
    {
        string query;
        cout << "Starting Snake Game..." << endl;
        query = "play snake game online";
        replace(query.begin(), query.end(), ' ', '+');
        string url = "start https://www.google.com/search?q=" + query;
        system(url.c_str());
    }
};
int main()
{
    tree a;
    char s;
    a.greet();
    do
    {
        a.start();
        cout << "\nAnything else sir? (yes-y or no-n) ";
        cin >> s;
        a.Delete(s);
    } while (s == 'y');
    return 0;
}
