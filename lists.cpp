#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

template <class T>
struct List{
    T data;
    List* head = NULL;
    List* tail = NULL;
    List* next = NULL;
};

template <class T>
struct Node{
    T data;
    List* next = NULL;
    List* prev = NULL;
};

template <class T>
void InsertarNodoFinal(List *&list_last_item){
    List *node = nullptr;
    node = new List<T>;
    list_last_item->next = node;
    node->prev = list_last_item;
    list_last_item = node;
    return;
}

template <class T>
void InsertarNodoPrincipio(List *&list){
    List *node = nullptr;
    node = new List<T>;
    list->prev = node;
    node->next = list;
    list = node;
    return;
}

template <class T>
void ImprimirLista(List *list){
    List *temp = nullptr;
    temp = list;
    while(temp!=NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

template <class T>
void ImprimirListaReversa(List *list_last_item){
    List *temp = nullptr;
    temp = list_last_item;
    while(temp!=NULL){
        cout << temp->data << endl;
        temp = temp->prev;
    }
}

template <class T>
void AvanzarElementoLista(List *&list_ptr){

    if(list_ptr->next != NULL){
        list_ptr = list_ptr->next;
    }
    return;
}

template <class T>
void RetrocederElementoLista(List *&list_ptr){
    if(list_ptr->prev != NULL){
        list_ptr = list_ptr->prev;
    }
    return;
}

template <class T>
void CrearLista(List *&list, List *&last, List *&actual){
    List *node = nullptr;
    node = new List<T>;
    list = node;
    last = node;
    actual = node;
    return;
}

template <class T>
bool InsertarEnPosicion(List *&list, int position){
    List *node = nullptr, *temp = nullptr;
    node = new List<T>;
    temp = list;
    if(position<1){
        return false;
    }
    for(int i=1; i<position-1;i++){
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
    node->prev = temp;
    node->next->prev = node;
    return;
}

int main(){

    List *lista = nullptr,
		 *last = nullptr,
		 *actual = nullptr;

    CrearLista<List>(lista,last,actual);

    lista->data = 1;

    for(int i=2; i<=100;i++){
        InsertarNodoFinal<List>(last);
        last->data = i;
    }

    InsertarEnPosicion<List>(lista,2);
	
    ImprimirListaReversa<List>(last);

    getch();
    return 0;

}

