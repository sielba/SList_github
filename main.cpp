#include <cstdio>
#include <ctime>

struct Data
{
    char imie[13];
    char nazwisko[13];
};

struct Node
{
    Node* next;
    int index;
    Data data;

} *root = NULL;


Node* findBefore(int index)
{

    if (root != NULL && root->index == index)
        return root;
    else
    {

        Node* tmp = root;
        while (tmp != NULL && tmp->next != NULL)
        {
            if (tmp->next->index == index)
                return tmp;
            tmp = tmp->next;
        }

        return NULL;
    }
}


Node* find(int index)
{
    Node* tmp = root;
    while (tmp != NULL)
    {
        if (tmp->index == index)
            return tmp;
        tmp = tmp->next;
    }

    return NULL;
}


bool add(int index, Data data)
{
    Node* tmp = root;
    root = new Node;
    root->next = tmp;
    root->data = data;
    root->index = index;

    return true;
}

void remove(Node* node)
{

    printf("bla\n");
    Node* tmp;
    if (node == root)
    {
        printf("bla_root\n");
        tmp = root;
        root = tmp->next;
        tmp = NULL;
        printf("bla_root 2\n");
        return;
    }
    printf("bla\n");
    tmp = node->next;
    printf("bla\n");
    if(node->next->next != NULL)
    {
        printf("bla-if\n");
        node->next = node->next->next;
    }
    else 
    {
        printf("bla_else\n");
        delete node->next;
        delete tmp;
    }
    return;
}

void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d %s %s\n", node->index, node->data.imie, node->data.nazwisko);
        node = node->next;
    }
}

int main()
{
    int n;
    char c;
    Data dane;
    unsigned long time = 0;

    while(1)
    {
        scanf("%c",&c);
        switch (c)
        {
        case 'a': //if(c=='a')
        {
            scanf("%d %s %s", &n, dane.imie, dane.nazwisko);
            if(add(n,dane))
                printf("Added.\n");
            else
                printf("Not added - Already here.\n");
        }
        break;
        case 'f': //else if(c=='f')
        {
            scanf("%d", &n);
            Node *f = find(n);
            if (f) printf("Indeks: %d Imie: %s Nazwisko %s\n", f->index, f->data.imie, f->data.nazwisko);
            else printf("Nie znaleziono kurwa.\n");
        }
        break;
        case 'd': //else if(c=='r')
        {
            scanf("%d", &n);
            Node *f = find(n);

            if(f)
            {
                printf("usuwa\n");
                remove(f);
                printf("usuniete\n");

            }
            else printf("Nie znaleziono kurwa(usun).\n");
        }
        break;
        case 's':
            time = clock();
            break;
        case 't':
            printf("%lu \n", clock() - time);
            break;
        case 'p': //else
        {

            printList(root);
        }
        }
    }
}

