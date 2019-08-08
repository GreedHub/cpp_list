#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;


struct List{
    int data;
    List* next = NULL;
    List* prev = NULL;
};

template <class T>
void InsertarNodoFinal(T *&list_last_item){
    T *node = nullptr;
    node = new T;
    list_last_item->next = node;
    node->prev = list_last_item;
    list_last_item = node;
    return;
}

template <class T>
void InsertarNodoPrincipio(T *&list){
    T *node = nullptr;
    node = new T;
    list->prev = node;
    node->next = list;
    list = node;
    return;
}

template <class T>
void ImprimirLista(T *list){
    T *temp = nullptr;
    temp = list;
    while(temp!=NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

template <class T>
void ImprimirListaReversa(T *list_last_item){
    T *temp = nullptr;
    temp = list_last_item;
    while(temp!=NULL){
        cout << temp->data << endl;
        temp = temp->prev;
    }
}

template <class T>
void AvanzarElementoLista(T *&list_ptr){

    if(list_ptr->next != NULL){
        list_ptr = list_ptr->next;
    }
    return;
}

template <class T>
void RetrocederElementoLista(T *&list_ptr){
    if(list_ptr->prev != NULL){
        list_ptr = list_ptr->prev;
    }
    return;
}

template <class T>
void CrearLista(T *&list, T *&last, T *&actual){
    T *node = nullptr;
    node = new T;
    list = node;
    last = node;
    actual = node;
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

    InsertarNodoPrincipio<List>(lista);
    lista->data = 0;

   // ImprimirListaReversa<List>(last);

    actual = lista;
    cout << actual->data;
    AvanzarElementoLista(actual);
    cout << actual->data;
    RetrocederElementoLista(actual);
    cout << actual->data;
    getch();
    return 0;

}

