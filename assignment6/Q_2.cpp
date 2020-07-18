//17114049 MULA RAM

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
struct node 
{
    int data;
    node* right_child;
    node* left_child;
};

class grey_tree
{
    node* root;

public:
    grey_tree(vector<int> vect)
    {
        sort(vect.begin(), vect.end());
        
        root = this -> make_grey_tree(vect, 0, vect.size() - 1);
    }

    node* make_grey_tree(vector<int> vect, int start, int end)
    {
        node* temp = nullptr;

        if((end == start))
        {
            node* new_node = new node;

            new_node -> right_child = nullptr;
            new_node -> left_child = nullptr;
            new_node -> data = vect.at(start);

            return new_node;
        }

        int middle = start + (end - start) / 2;

        node* root = new node;
        root -> data = vect.at(middle);
        root -> left_child = make_grey_tree(vect, start, middle);
        root -> right_child = make_grey_tree(vect, middle + 1, end);

        return root;
    }

    void print(node *temp, int space) 
    { 
        if (temp == NULL) 
            return; 
    
        space += 10; 
    
        print(temp-> right_child, space); 
    
        cout << endl;
        for (int i = 10; i < space; i++) 
            cout << " "; 
        cout << temp -> data << endl; 
    
        print(temp->left_child, space); 
    } 

    void print()
    {
        print(root, 0);
    }

    int count_a_b(int a, int b)
    {
        count_a_b(a, b, root);
    }

    int count_a_b(int a, int b, node* temp)
    {
        int count = 0;

        if(temp == nullptr)
            return 0;

        if(temp -> data > b)
        {
            count += count_a_b(a, b, temp -> left_child);
            return count;
        }
        else if(temp -> data < a)
        {
            count += count_a_b(a, b, temp -> right_child);
            return count;
        }
        else
        {
            count += 1;
            count += count_a_b(a, b, temp -> left_child);
            count += count_a_b(a, b, temp -> right_child);

            return count;
        }
    }

    node* get_root()
    {
        return root;
    }

    int get_new_left_max(node* temp)
    {
        if(temp -> right_child == nullptr)
            return temp -> data;

        int value = get_new_left_max(temp -> right_child);

        return value;
    }

    void delete_element(int element)
    {
        delete_element(element, root);
    }

    void delete_element(int element, node* temp)
    {
        if(temp -> right_child -> data == element)
        {
            if(temp -> right_child -> left_child == nullptr &&
                temp -> right_child -> right_child == nullptr)
            {
                delete temp -> right_child;
                temp -> right_child = nullptr;
                return;
            }
        }

        if(temp -> left_child -> data == element)
        {
            if(temp -> right_child -> left_child == nullptr &&
                temp -> right_child -> right_child == nullptr)
            {
                delete temp -> left_child;
                temp -> left_child = nullptr;
                return;
            }
        }


        if(temp -> data > element)
        {
            delete_element(element, temp -> left_child);
        }
        else if(temp -> data < element)
        {
            delete_element(element, temp -> right_child);
        }
        else
        {
            delete_element(element, temp -> left_child);
        }

        if(temp -> data == element)
        {
            int val = get_new_left_max(temp -> left_child);
            temp -> data = val;
        }
        
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vect = {6, 15, 17, 21, 24, 33, 42, 51, 52, 57, 65, 73, 78};

    // Construct grey tree
    cout << "Initial Grey Tree: " << endl;
    grey_tree our_grey_tee(vect);
    // NOTE:tree will be printed rotated to left
    our_grey_tee.print();
    cout << endl;

    // Count number of nodes between 2 numbers
    int count = our_grey_tee.count_a_b(15, 21);
    cout << "Num elements are:" << count << endl;

    // Delete a given value from tree
    cout << "Grey tree after deletion: " << endl;
    our_grey_tee.delete_element(33);
    our_grey_tee.print();
    cout << endl;

    return 0;
}
