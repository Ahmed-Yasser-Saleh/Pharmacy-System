
 #include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

//prepared by Ahmed yasser Saleh & Ahmed Nasser Ibrahim

class node {
    public :
    string name ;
    double price ;
    node *next , *prev;
};
class double_link_list{
    private :
        node *first , *last ;
       int index ;
    public :
    double_link_list(): first(NULL) , last(NULL) , index(0) {
        cout << "Welcome to our double linked list class\n";
        cout <<"--------------------------------------------\n";
    }

    bool is_empty(){
        return first == NULL ;
    }

    void insert_front( string product , int pr){
        node *newnode = new node ;
        newnode ->name = product ;
        newnode -> price = pr ;
        newnode -> next = first ;
        newnode -> prev = NULL ;
        if ( is_empty()){
        last = newnode ;
        }
        else {
        first -> prev = newnode ;
        }
        first = newnode ;
    }

    void insert_back( string product , int pr){
        node *newnode = new node ;
        newnode ->name = product ;
        newnode -> price = pr ;
        newnode -> next = NULL ;
        newnode -> prev = last ;
        if ( is_empty()){
        first = newnode ;
        }
        else {
        last -> next = newnode ;
        }
        last = newnode ;
    }

    void display(){
        node *temp = first ;
        if(first== NULL)
            cout << "List is empty\n";
        else{
        while ( temp != NULL){
            cout << temp -> name << " " << temp -> price << nl ;
            temp = temp -> next ;
        }
        }
    }

    node * search ( string product){
        index = 0 ;
        node *temp = first ;
        while ( temp != NULL && temp -> name != product ){
            temp = temp -> next ;
            index++ ;
        }
        if ( temp == NULL ){
            cout << "NOT FOUND " << nl ;
            return NULL ;
        }
        else
        return temp ;
    }

    void location(string product){
        if ( search(product) != NULL)
        cout << index << nl ;
    }

    void remove(string product){
        if ( search(product) == NULL ) return ;
        node * del = search(product) ;
        if ( del -> prev == NULL && del -> next == NULL ){
            cout << "NOW , list is empty " << nl ;
            first = NULL;
        }
        else if ( del -> prev != NULL and del -> next != NULL  ){
        del -> prev -> next = del -> next ;
        del -> next -> prev = del -> prev ;
        }
        else if ( del -> prev == NULL ) {
            del -> next -> prev = NULL ;
            first = del -> next ;
        }
        else if ( del -> next == NULL ){
            del -> prev -> next = NULL ;
            last = del -> prev ;
        }
        delete del ;
    }

    void  modify(string product , double newprice ){
        if (search(product) == NULL ) return ;
        node *temp = search(product) ;
        temp -> price = newprice ;
    }
    double bill ( string product ){
        node *temp = search(product) ;
        return temp -> price ;
    }
};

   int chose (){
    cout << " press 1 to modify " << nl ;
    cout << " press 2 to remove " << nl ;
    cout << " press 3 to extract the bill " << nl ;
    cout << " press 4 to display " << nl ;
    cout << " press 5 to find the location of product  " << nl ;
    cout << " press 6 to insert new product  " << nl ;
    cout << " press 0 to exit " << nl ;
    int choose ; cin >> choose ;
    return choose ;
  }
 int main(){
    double_link_list lis ;
    string product ;
    double  price ;
    int sum = 0 ;
    cout << "how many product do you want to insert " << nl ;
    int t ; cin >> t ;
    cout << " please enter your product and its price " << nl ;
    for ( int i = 0 ; i < t ; i++ ){
    cin >> product >> price  ;
    lis.insert_back(product,price) ;
    }
    int choose = chose() ;
    while ( choose != 0){
        string product ;
            double newprice ;
        if (choose == 1){
            cout << " please enter the product and its newprice " << nl ;
            cin >> product >> newprice ;
            lis.modify(product , newprice) ;
        }
        else if ( choose == 2){
            cout << "enter the product that you want to remove " << nl ;
            cin >> product ;
            lis.remove(product) ;
        }
        else if ( choose == 3){
            cout << "how many product are bought  " << nl ;
            int t ; cin >> t ;
            for ( int i = 1 ; i <= t ; i++){
            cout << "enter product " << i << nl ;
            cin >> product ;
            sum += lis.bill(product) ;
            }
            cout << "bill = " << sum << nl ;
            sum = 0 ;
        }
        else if ( choose == 4){
            cout << "list = " << nl ;
            lis.display() ;
        }
        else if ( choose == 5){
            cout << "which product you want its location" << nl ;
            cin >> product ;
            cout << "product location of " << product << " is ";
            lis.location(product) ;
            cout << nl ;
        }
        else if (choose == 6 ){
            cout << "how many product do you want to insert " << nl ;
            int t ; cin >> t ;
            cout << "please enter your product and its price " << nl ;
            for ( int i = 0 ; i < t ; i++ ){
            cin >> product >> price  ;
            lis.insert_back(product,price) ;
            }
        }
      choose =  chose() ;
    }
    cout << "prepared by eng : Ahmed Yasser Saleh & Ahmed Nasser Ibrahim" << nl ;
    cout << "thank you" << nl ;
  return 0 ;
}
