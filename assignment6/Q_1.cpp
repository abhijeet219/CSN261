#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

void printLL(node* head){
    node* temp = head;
    int tempData;
    while(temp!=NULL){
        tempData = temp->data;
        cout<<tempData<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void printHashMapSepChaining(node* myMap[],short helper[], int len){
    for (int i=0; i<len; i++) {
        cout<<i<<"\t:\t";
        if(helper[i]==0){
            cout<<"NULL"<<endl;
        }else{
            printLL(myMap[i]);
        }
    }
}

void printHashMapLinearProbing(int myMap[], int hashlen){
    for (int i=0; i<hashlen; i++) {
        cout<<i<<"\t:\t"<<myMap[i]<<endl;
    }
}

int main(){
    int arr[] = {9,17,89,103,211,64,516,81,32,76,21,137};

    //Following is the code to make hashmap of arr[] using seperate chaining
    cout<<"==============Seperate Chaining============="<<endl;
    cout<<"Index\t:\tSequence"<<endl;
    node* myHashMap[6];
    short emptyOrFilled[] = {0,0,0,0,0,0};
    int tempElem, tempIndex;
    node* tempNode;
    for (int i=0; i<12; i++) {
        tempElem = arr[i];
        tempIndex = (tempElem*3 + 4)%6;
        node* newNode = new node;
        newNode->data = arr[i];
        if(emptyOrFilled[tempIndex]==0){
            newNode->next=NULL;
            myHashMap[tempIndex]=newNode;
            emptyOrFilled[tempIndex]=1;
        }else{
            tempNode=myHashMap[tempIndex];
            newNode->next = tempNode;
            myHashMap[tempIndex]=newNode;
        }
    }
    printHashMapSepChaining(myHashMap,emptyOrFilled,6);

    int maxlen=0, count;
    int maxIndex=0;
    for (int j=0; j<6; j++) {
        if(emptyOrFilled[j]==1){
            tempNode = myHashMap[j];
            count=0;
            while(tempNode!=NULL){
                count+=1;
                tempNode=tempNode->next;
            }
            if(count>maxlen){
                maxlen=count;
                maxIndex=j;
            }
        }
    }
    cout<<"Largest sequence of length "<<maxlen<<" at index "<<maxIndex<<endl;
    cout<<"============================================"<<endl;

    //Following is the code to make hashmap of arr[] using linear probing
    cout<<"================Linear Probing=============="<<endl;
    cout<<"Index\t:\tSequence"<<endl;
    int linearProbingHashMap[12];
    int prevIndex, nextIndex;
    short emptyOrNot[12];
    for (int k=0; k<12; k++) {
        tempElem = arr[k];
        tempIndex=(3*tempElem + 4)%12;
        if(emptyOrNot[tempIndex]==0){
            linearProbingHashMap[tempIndex] = tempElem;
            emptyOrNot[tempIndex]=1;
        }else{
            while(true){
                tempIndex+=1;
                tempIndex%=12;
                prevIndex = tempIndex-1;
                nextIndex = tempIndex+1;
                if(emptyOrNot[tempIndex]==0){
                    if(tempElem%2==0){
                        if(prevIndex==-1){
                            if(emptyOrNot[nextIndex]==1 && linearProbingHashMap[nextIndex]%2!=0){
                                linearProbingHashMap[tempIndex] = tempElem;
                                emptyOrNot[tempIndex]=1;
                                break;
                            }else if(emptyOrNot[nextIndex]==0){
                                linearProbingHashMap[tempIndex] = tempElem;
                                emptyOrNot[tempIndex]=1;
                                break;
                            }
                        }else if(nextIndex==12){
                            if(emptyOrNot[prevIndex]==1 && linearProbingHashMap[prevIndex]%2!=0){
                                linearProbingHashMap[tempIndex] = tempElem;
                                emptyOrNot[tempIndex]=1;
                                break;
                            }else if(emptyOrNot[prevIndex]==0){
                                linearProbingHashMap[tempIndex] = tempElem;
                                emptyOrNot[tempIndex]=1;
                                break;
                            }
                        }else{
                            if(emptyOrNot[nextIndex]==0 && emptyOrNot[prevIndex]==0){
                                linearProbingHashMap[tempIndex] = tempElem;
                                emptyOrNot[tempIndex]=1;
                                break;
                            }else if(emptyOrNot[prevIndex]==1 && linearProbingHashMap[prevIndex]%2!=0 && emptyOrNot[nextIndex]==0){
                                linearProbingHashMap[tempIndex] = tempElem;
                                emptyOrNot[tempIndex]=1;
                                break;
                            }else if(emptyOrNot[prevIndex]==0 && linearProbingHashMap[nextIndex]%2!=0 && emptyOrNot[nextIndex]==1){
                                linearProbingHashMap[tempIndex] = tempElem;
                                emptyOrNot[tempIndex]=1;
                                break;
                            }else if(emptyOrNot[prevIndex]==1 && linearProbingHashMap[prevIndex]%2!=0 && emptyOrNot[nextIndex]==0 && linearProbingHashMap[nextIndex]%2!=0){
                                linearProbingHashMap[tempIndex] = tempElem;
                                emptyOrNot[tempIndex]=1;
                                break;
                            }
                        }
                    }else{
                        linearProbingHashMap[tempIndex] = tempElem;
                        emptyOrNot[tempIndex]=1;
                        break;
                    }
                }
            }
        }
    }
    printHashMapLinearProbing(linearProbingHashMap,12);
    cout<<"============================================"<<endl;
    return 0;
}




























