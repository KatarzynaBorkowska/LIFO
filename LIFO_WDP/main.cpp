// zad 5_2 LIFO
// Katarzyna Borkowska 7 Y1S1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int v;
    struct node *next;

}node;

node *head = NULL;
int IsEmpty(){

 if(head == NULL) return 1;
 else
     return 0;
}

bool Push() {
    node *nowenode = new node;
    if (nowenode == NULL) return false;

    
    printf("Elm ktory chcesz dodac to: ");
    scanf("%d",&nowenode->v);

    nowenode->next = head;
    head = nowenode;
    return true;
}
void Pop(){
    if(IsEmpty())
    {
       printf("Stos jest pusty\n");
    }
    else
    {
        node *tmp = head;
        head = head->next;
        free(tmp);
    }

}
void Top() {

    if(IsEmpty())
    {
       printf("Stos jest pusty\n");
    }
    else{
        printf("Top = %d\n",head->v);
    }
}
void Clear() {
    while(IsEmpty() != 1)
        Pop();
}
int main() {
    int n = -1;
    printf("Wybierz czynnosc:\n"
           "1 - odczytuje element ze szczytu stosu\n"
           "2 - odklada element na szczyt stosu\n"
           "3 - zdejmuje element ze szczytu stosu\n"
           "4 - sprawdza czy stos jest pusty\n"
           "5 - czysci stos\n"
           "0 - KONIEC\n");
    while(n != 0)
    {
        scanf("%d",&n);
        switch (n) {
            case 1:
                Top();
                break;
            case 2:
                Push();
                break;
            case 3:
                Pop();
                break;
            case 4:
               if(IsEmpty() == 1)
                    printf("Stos jest Pusty\n");
                else
                    printf("Stos nie jest Pusty\n");
                break;
            case 5:
                Clear();
                printf("Wyczyszczone.\n");
                break;
                
            default:
                break;
        }
    }
    return 0;
}
