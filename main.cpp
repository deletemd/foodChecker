#include <iostream>
#include "dinerLinkedList.h"



using namespace  std;

Diner *currentDiner = nullptr;
int currentMenuOption;
dinerLinkedList dinerList;
restrictionLinkedList restrictionList;
mealLinkedList mealList;


void printInstructions(){
  cout<<"This program was developed to help keep records of food plans for multiple users. This could be used in a homeless shelter, food shelter, or even school cafeterias and families. " <<endl <<endl<<"The program allows users to add diners, create and assign restrictions for them, and then create and assign meals." <<endl <<endl<<"Once you have assinged all of this, you can use the see all diners option to see if your plan needs any adjusting";
}
void addNewMeal(){
   string newName;
  float calories;
  string _ingredient;
  ingredientLinkedList * _ingredients = new ingredientLinkedList();
  char option ='z';
  bool mealExists = false;
  cout << endl << endl << "ADD NEW Meal:" <<endl;
  cout <<"Input new Meal's name"<<endl;
  cin >> newName;
  cout <<"Input total calories"<<endl;
  cin >> calories;

  if(mealList.getLength() >0)
  {
    mealList.search(newName);

    if(mealList.getData() != nullptr)
    {
      cout << "This restriction already exists"<< endl <<endl ;
      mealExists = true;
    }
    
  }

  if(!mealExists){
   
  mealList.addMeal(newName,_ingredients,calories);

  option = 'z';

  while (option != 'n'){
 cout <<endl<<"Would you like to add an ingredient to this restriction? (y/n): "; 
  cin >> option;

      if(option == 'y')
  {
      string newName;
               cout<< endl<<"What ingredient would you like to add "<<endl;
 cin >>newName;
    _ingredients->addIngredient(newName);
  }
    }

if(option == 'n')
  {
currentMenuOption = 0;
  }
    
  }
}

void setPresetData(){
  dinerList.addDiner("Deladem",22,65.7,170,'m');
  dinerList.addDiner("Alex",42,75.7,170,'f');
    dinerList.addDiner("Zed",62,70.7,170,'m');
  dinerList.addDiner("Roberta",82,69.7,170,'f');
    dinerList.addDiner("Jason",24,55.7,170,'m');
  dinerList.addDiner("John",32,85.7,170,'m');
  
  ingredientLinkedList *_ingredients = new ingredientLinkedList();
  _ingredients->addIngredient("Cheese");
  _ingredients->addIngredient("Milk");
  restrictionList.addRestriction("Diary",_ingredients);

   _ingredients = new ingredientLinkedList();
  _ingredients->addIngredient("Chicken");
  _ingredients->addIngredient("Beef");
  _ingredients->addIngredient("Pork");
  restrictionList.addRestriction("Vegetarian",_ingredients);

  _ingredients = new ingredientLinkedList();
  _ingredients->addIngredient("Rice");
  _ingredients->addIngredient("Pork");
  mealList.addMeal("Red Beans and Rice",_ingredients,700);
  }

void addRestrictions(){
   string newName;
  string _ingredient;
  ingredientLinkedList * _ingredients = new ingredientLinkedList();
  char option ='z';
  bool restrictionExists = false;
  cout << endl << endl << "ADD NEW RESTRICTION:" <<endl;
  cout <<"Input new restrcition's name"<<endl;
  cin >> newName;

  if(restrictionList.getLength() >0)
  {
    restrictionList.search(newName);

    if(restrictionList.getData() != nullptr)
    {
      cout << "This restriction already exists"<< endl <<endl ;
      restrictionExists = true;
    }
    
  }

  if(!restrictionExists){
   
  restrictionList.addRestriction(newName,_ingredients);

  option = 'z';

  while (option != 'n'){
 cout <<endl<<"Would you like to add an ingredient to this restriction? (y/n): "; 
  cin >> option;

      if(option == 'y')
  {
      string newName;
               cout<< endl<<"What ingredient would you like to add "<<endl;
 cin >>newName;
    _ingredients->addIngredient(newName);
  }
    }

if(option == 'n')
  {
currentMenuOption = 0;
  }
    
  }
}

void getAllRestrictions(){
   
  restrictionList.printInformation();

  
  }

void addNewDiner(){
  string newName;
  int newAge;
  float newHeight;
  float newWeight;
  char newSex= 'z';
  char option ='z';
  bool userExists = false;
  cout << endl << endl << "ADD NEW DINER:" <<endl;
  cout <<"Input new diner's name"<<endl;
  cin >> newName;

  if(dinerList.getLength() >0)
  {
    dinerList.search(newName);

    if(dinerList.getData() != nullptr)
    {
      cout << "This User already exists"<< endl <<endl ;
      userExists = true;
    }
    
  }

  if(!userExists){
    cout <<"Input new diner's age"<<endl;
   cin >> newAge;
  cout <<"Input new diner's height in centimeters"<<endl;
   cin >> newHeight;
  cout <<"Input new diner's weight in kilograms"<<endl;
   cin >> newWeight;
    while (newSex != 'm' && newSex != 'f'){
     cout <<"Input new diner's sex(m/f) "<<endl;
   cin >> newSex;
      }
  dinerList.addDiner(newName,newAge,newWeight,newHeight,newSex);
  while (option != 'y' && option != 'n'){
 cout <<endl<<"Would you like to add a reststriction for " << newName<<" ? (y/n): "; 
  cin >> option;
    
  if(option == 'y')
  {
     dinerList.search(newName);
    if(dinerList.getData() != nullptr)
    {
     currentDiner = dinerList.getData()->getData();
    restrictionList.printInformation();

          int userChoice=0;
      while(userChoice <1 || userChoice> restrictionList.getLength()){
        if(currentDiner->getRestrictions()->getHead() != nullptr){
          cout << currentDiner->getRestrictions()->getHead()->getData()->getName();
        }
         cout <<endl <<"Which restriction would you like to add?"<<endl;
      cin >>userChoice;
      }

         restrictionList.getData(userChoice);

  bool restrictionExists = false;
  if(currentDiner->getRestrictions()->getLength() >0)
  {
    currentDiner->getRestrictions()->search(restrictionList.getData()->getData()->getName());

    if(currentDiner->getRestrictions()->getData() != nullptr)
    {
      cout << "This restriction already exists"<< endl <<endl ;
      restrictionExists = true;
    }
    
         }

         
  if(!restrictionExists){    
  currentDiner->getRestrictions()->addRestriction(restrictionList.getData());
    }     

      
  
    }
  
}
    }
  option = 'z';
 while (option != 'y' && option != 'n'){
 cout <<endl<<"Would you like to add a meal for " << newName<<" ? (y/n): "; 
  cin >> option;
    
  if(option == 'y')
  {
     dinerList.search(newName);
    if(dinerList.getData() != nullptr)
    {
     currentDiner = dinerList.getData()->getData();
    mealList.printInformation();
          int userChoice=0;
      while(userChoice <1 || userChoice> mealList.getLength()){
        if(currentDiner->getMeals()->getHead() != nullptr){
          cout << currentDiner->getMeals()->getHead()->getData()->getName();
         }
         cout <<endl <<"Which meal would you like to add?"<<endl;
      cin >>userChoice;
      }

         mealList.getData(userChoice);
cout<<"!";
  bool mealExists = false;
  if(currentDiner->getMeals()->getLength() >0)
  {
    currentDiner->getMeals()->search(restrictionList.getData()->getData()->getName());

    if(currentDiner->getMeals()->getData() != nullptr)
    {
      cout << "This meal already exists"<< endl <<endl ;
      mealExists = true;
    }
    
         }

         
  if(!mealExists){    
  currentDiner->getMeals()->addMeal(mealList.getData());
    }     

      
  
    }
  
}
    }
    option ='z';
  while (option != 'y' && option != 'n'){
 cout <<endl<<"Would you like to add another diner? (y/n): "; 
  cin >> option;
    }
  if(option == 'y')
  {
    addNewDiner();
  }
if(option == 'n')
  {
currentMenuOption = 0;
  }
    
  }
}

void getAllDiners(){
    cout<< "ALL DINERS"<<endl;
  if(dinerList.getLength() ==0){
    cout<< "There are no patrons or diners in the system at the moment."<< endl ;
  }
  else{
  for(int eachDiner =1; eachDiner <= dinerList.getLength(); eachDiner ++){
    dinerList.setData(dinerList.getData(eachDiner));
    cout << eachDiner << ": " << dinerList.getData()->getData()->getName()<<endl;
    }
  }
  cout<<endl;
}

void searchDiner(){
  string query = "";
  cout<< "Please enter the full name of who you would like to look for: ";
  cin >>query;
  dinerList.search(query);
  if(dinerList.getData() == nullptr)
  {
    char choice = 'z';

    while(choice != 'y' && choice != 'n'){
    cout << query << " could not be found would you like to try again(y/n)" <<endl;
      cin >>choice;
      }

    if(choice == 'y')
    {
      searchDiner();
    }
    
  }
  else{
    currentDiner = dinerList.getData()->getData();
    currentDiner->printInformation();
    dinerList.setData(nullptr);
  }
}

void menu(){
  cout<< "MENU: "<<endl<<"1. Instructions"<<endl<< "2. Add new Diner"<< endl<<"3. See All Diners " << endl<<"4. Search For Diner " << endl<<"5. Add new Restriction"<< endl<<"6. See All Restrictions " << endl<<"7. Add new Meal"<<endl<<"8. See All Meals "<<endl<<"9.Quit"<<"" <<endl <<endl;

  cout <<"Please input a menu option: ";
  cin >> currentMenuOption;

  if(currentMenuOption == 1)
  {
      cout<<endl;
    printInstructions();
    cout<<endl;
  }
  if(currentMenuOption == 2)
  {
      cout<<endl;
    addNewDiner();
    cout<<endl;
  }

  
  if(currentMenuOption == 3)
  {
    cout<<endl;
    getAllDiners();

 if(dinerList.getLength() >=1){
    char choice = 'z';
    while (choice != 'e' && choice != 'v'&& choice != 'm' && choice != 'r')
    {
          cout<< "Would you like to edit(e) a user, view(v) a user, remove(r) a user, or continue to menu(m)?"<< endl;
      cin>>choice;
    }

    if(choice =='e'){
            int userChoice=0;
      while(userChoice <1 || userChoice> dinerList.getLength()){
         cout <<endl <<"Which user would you like to edit?"<<endl;
      cin >>userChoice;
      }
     currentDiner = dinerList.getData(userChoice)->getData();
      currentDiner->printInformation();
int id = userChoice;        
         
userChoice = 0;
       while(userChoice <1 || userChoice> 6){
      cout<< endl<< "Would you like to edit their: "<<endl<<"Name(1)"<<endl<<"Age(2)"<<endl<<"Height(3)"<<endl<<"Weight(4)"<<endl<<"Restrictions(5)"<<endl<<"Meals(6)";
      cin >>userChoice;
      }

      if(userChoice == 1 && id == 1)
      {
       string newName;
              cout<< endl<<"What Name would you like to change to "<<endl;
cin >>newName;

        dinerList.setHead(dinerList.getHead()->getNextNode());
        dinerList.addDiner(newName,currentDiner->getAge(),currentDiner->getWeight(), currentDiner->getHeight(),currentDiner->getSex());
dinerList.removeDiner(nullptr);
        }
         else if(userChoice ==1){
               
       string newName;
              cout<< endl<<"What Name would you like to change to "<<endl;
cin >>newName;
        dinerList.setData(nullptr);
        dinerList.addDiner(newName,currentDiner->getAge(),currentDiner->getWeight(), currentDiner->getHeight(), currentDiner->getSex());
dinerList.removeDiner(dinerList.getData(id));
        dinerList.setData(nullptr);
           
         }
         else if(userChoice ==2){
           int newAge;
                         cout<< endl<<"Please enter a new age "<<endl;
cin>> newAge;
        currentDiner->setAge(newAge);
      }
          else if(userChoice ==3){
           float newHeight;
                         cout<< endl<<"Please enter a new height(cm) "<<endl;
cin>> newHeight;
        currentDiner->setHeight(newHeight);
      }
       else if(userChoice ==4){
           float newWeight;
                         cout<< endl<<"Please enter a new weight(kg) "<<endl;
cin>> newWeight;
        currentDiner->setHeight(newWeight);
      }
       else if(userChoice ==5){
        restrictionList.printInformation(); 

         int userChoice=0;
      while(userChoice <1 || userChoice> restrictionList.getLength()){
         cout <<endl <<"Which restriction would you like to add?"<<endl;
      cin >>userChoice;
      }

         restrictionList.getData(userChoice);

  bool restrictionExists = false;
  if(currentDiner->getRestrictions()->getLength() >0)
  {
    currentDiner->getRestrictions()->search(restrictionList.getData()->getData()->getName());

    if(currentDiner->getRestrictions()->getData() != nullptr)
    {
      cout << "This restriction already exists"<< endl <<endl ;
      restrictionExists = true;
    }
    
         }

         
  if(!restrictionExists){
    
  currentDiner->getRestrictions()->addRestriction(restrictionList.getData());
    }
      }

       else if(userChoice ==6){
        mealList.printInformation(); 

         int userChoice=0;
      while(userChoice <1 || userChoice> mealList.getLength()){
         cout <<endl <<"Which meal would you like to add?"<<endl;
      cin >>userChoice;
      }

         mealList.getData(userChoice);

  bool mealExists = false;
  if(currentDiner->getMeals()->getLength() >0)
  {
    currentDiner->getMeals()->search(mealList.getData()->getData()->getName());

    if(currentDiner->getMeals()->getData() != nullptr)
    {
      cout << "This restriction already exists"<< endl <<endl ;
      mealExists = true;
    }
    
         }

         
  if(!mealExists){
   cout<<currentDiner;
    
  currentDiner->getMeals()->addMeal(mealList.getData());
    }
      }
      }
      
    if(choice == 'v')
    {
      int userChoice=0;
      while(userChoice <1 || userChoice> dinerList.getLength()){
         cout <<endl <<"Which user would you like to view?"<<endl;
      cin >>userChoice;
      }
     currentDiner = dinerList.getData(userChoice)->getData();
      currentDiner->printInformation();
      }

    if(choice =='r')
    {

      int userChoice=0;
      while(userChoice <1 || userChoice> dinerList.getLength()){
         cout <<endl <<"Which user would you like to remove?"<<endl;
      cin >>userChoice;
      }
      if(userChoice == 1){
        dinerList.removeDiner(nullptr);
        dinerList.setHead(dinerList.getHead()->getNextNode());
      }
      else{
             dinerNode* node = dinerList.getData(userChoice-1);
  dinerList.removeDiner(node);
      }
    
      }

    
    }
    cout<<endl;
  }
  
if(currentMenuOption == 4)
  {
      cout<<endl;
    searchDiner();
    cout<<endl;
  }

   if(currentMenuOption == 5)
  {
      cout<<endl;
    addRestrictions();
    cout<<endl;
  }

  
  if(currentMenuOption == 6)
  {
      cout<<endl;
    getAllRestrictions();

    if(restrictionList.getLength() >=1){
    char choice = 'z';
    while (choice != 'e' && choice != 'v'&& choice != 'm' && choice != 'r')
    {
          cout<< "Would you like to edit(e) a user, view(v) a user, remove(r) a user, or continue to menu(m)?"<< endl;
      cin>>choice;
    }

    if(choice =='e'){
            int userChoice=0;
      while(userChoice <1 || userChoice> restrictionList.getLength()){
         cout <<endl <<"Which restriction would you like to edit?"<<endl;
      cin >>userChoice;
      }
             
      restrictionList.getData(userChoice)->getData()->getIngredients()->printInformartion();
int id = userChoice;        
         
userChoice = 0;
       while(userChoice <1 || userChoice> 3){
      cout<< endl<< "Would you like to Add(1) or Remove(2) an ingredient? If not (3)";
      cin >>userChoice;
      }

      if(userChoice == 1)
      {
        string newName;
               cout<< endl<<"What ingredient would you like to add "<<endl;
 cin >>newName;
 restrictionList.getData(id)->getData()->getIngredients()->addIngredient(newName);
        }
         else if(userChoice ==2 ){
       
                 int userChoice=0;
      while(userChoice <1 || userChoice> restrictionList.getData()->getData()->getIngredients()->getLength()){
      
         cout <<endl <<"Which ingredient would you like to remove?"<<endl;
      cin >>userChoice;
      }
           if(userChoice == 1)
           {
             cout <<restrictionList.getData()->getData()->getIngredients()->getHead()->getNextNode()->getData();
             restrictionList.getData()->getData()->getIngredients()->setHead(restrictionList.getData()->getData()->getIngredients()->getHead()->getNextNode());
             cout << restrictionList.getData()->getData()->getIngredients()->getHead()->getData();
               restrictionList.getData()->getData()->getIngredients()->removeIngredient( nullptr);
           }
           else{
           cout<< restrictionList.getData()->getData()->getIngredients()->getData(userChoice)->getData();
                restrictionList.getData()->getData()->getIngredients()->removeIngredient( restrictionList.getData()->getData()->getIngredients()->getData(userChoice-1));    

           }
         
           
         }
       
      }
      
    if(choice == 'v')
    {
      int userChoice=0;
      while(userChoice <1 || userChoice> restrictionList.getLength()){
         cout <<endl <<"Which restiction would you like to view?"<<endl;
      cin >>userChoice;
      }
     restrictionList.getData(userChoice)->getData()->getIngredients()->printInformartion();
      }

    if(choice =='r')
    {

      int userChoice=0;
      while(userChoice <1 || userChoice> restrictionList.getLength()){
         cout <<endl <<"Which restriction would you like to remove?"<<endl;
      cin >>userChoice;
      }
      if(userChoice == 1){
        restrictionList.removeRestriction(nullptr);
        restrictionList.setHead(restrictionList.getHead()->getNextNode());
      }
      else{
             restrictionNode* node = restrictionList.getData(userChoice-1);
  restrictionList.removeRestriction(node);
      }
    
      }

    
    }
    cout<<endl;
   
  }

    if(currentMenuOption == 7){
      
      cout<<endl;
    addNewMeal();
    cout<<endl;
    }
      

  if(currentMenuOption == 8)
  {
      cout<<endl;
    mealList.printInformation();

    if(mealList.getLength() >=1){
    char choice = 'z';
    while (choice != 'e' && choice != 'v'&& choice != 'm' && choice != 'r')
    {
          cout<< "Would you like to edit(e) a meal, view(v) a meal, remove(r) a meal, or continue to menu(m)?"<< endl;
      cin>>choice;
    }

    if(choice =='e'){
            int userChoice=0;
      while(userChoice <1 || userChoice> mealList.getLength()){
         cout <<endl <<"Which restriction would you like to edit?"<<endl;
      cin >>userChoice;
      }
             
      mealList.getData(userChoice)->getData()->getIngredients()->printInformartion();
int id = userChoice;        
         
userChoice = 0;
       while(userChoice <1 || userChoice> 4){
      cout<< endl<< "Would you like to Add(1) or Remove(2) an ingredient, or change the total Calories for this meal(3)? If not (4)";
      cin >>userChoice;
      }

      if(userChoice == 1)
      {
        string newName;
               cout<< endl<<"What ingredient would you like to add "<<endl;
 cin >>newName;
 mealList.getData(id)->getData()->getIngredients()->addIngredient(newName);
        }
         else if(userChoice ==2 ){
       
                 int userChoice=0;
      while(userChoice <1 || userChoice> mealList.getData()->getData()->getIngredients()->getLength()){
      
         cout <<endl <<"Which ingredient would you like to remove?"<<endl;
      cin >>userChoice;
      }
           if(userChoice == 1)
           {
             mealList.getData()->getData()->getIngredients()->setHead(mealList.getData()->getData()->getIngredients()->getHead()->getNextNode());
               mealList.getData()->getData()->getIngredients()->removeIngredient( nullptr);
           }
           else{
           cout<< mealList.getData()->getData()->getIngredients()->getData(userChoice)->getData();
                mealList.getData()->getData()->getIngredients()->removeIngredient( mealList.getData()->getData()->getIngredients()->getData(userChoice-1));    

           }
         
           
         }

               else if(userChoice ==3 ){
                 float newCalories;
                  cout <<endl <<"How many calories should be in this meal?"<<endl;
      cin >>newCalories;
 mealList.getData(id)->getData()->setCalories(newCalories);
                 
                 }
      }
      
    if(choice == 'v')
    {
      int userChoice=0;
      while(userChoice <1 || userChoice> mealList.getLength()){
         cout <<endl <<"Which meal would you like to view?"<<endl;
      cin >>userChoice;
      }
     mealList.getData(userChoice)->getData()->getIngredients()->printInformartion();
      }

    if(choice =='r')
    {

      int userChoice=0;
      while(userChoice <1 || userChoice> mealList.getLength()){
         cout <<endl <<"Which meal would you like to remove?"<<endl;
      cin >>userChoice;
      }
      if(userChoice == 1){
        mealList.removeMeal(nullptr);
        mealList.setHead(mealList.getHead()->getNextNode());
      }
      else{
             mealNode* node = mealList.getData(userChoice-1);
  mealList.removeMeal(node);
      }
    
      }

    
    }
    cout<<endl;
   
  }
}



int main() {
  setPresetData();
  while(currentMenuOption != 9)
    {
       menu(); 
    }
  // Diner diner = new Diner("Deladem",22,65.7,170);
  return 0;
}