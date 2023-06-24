#include <iostream>
#include <string>

/*
    The initialization constructor allows you to create a productType object 
    and initialize its attributes with the given values. The default constructor 
    initializes the attributes with default values.

    The class also has constant accessor functions for each attribute, which 
    allow you to retrieve the value of an attribute without being able to modify it. 
    The accessor functions are getName, getPrice, and getDescription, which return 
    the values of the name_, price_, and description_ attributes, respectively.

*/

class productType {
    
    // Constructor with formal parameters
    public: productType(const std::string& name, const std::string& description, double price) {
        name_ = name;
        price_ = price;
        description_ = description;
    }

    // Default constructor
    public: productType() {
        name_ = "";
        price_ = 0.0; 
        description_ = "";
    }

    // Constant accessor functions
    public: std::string getName() const { return name_; }
    public: double getPrice() const { return price_; }
    public: std::string getDescription() const { return description_; }

    private: std::string name_;
    private: double price_;
    private: std::string description_;
};
/*
    The sectionType class represents a section in a supermarket. It has several 
    private member variables:

    name: a string representing the name of the section.
    size: an integer representing the maximum number of products that can 
        be stored in the section.
    products: an array of strings representing the products in the section.
    numProducts: an integer representing the number of products currently 
        in the section.

    The sectionType class has two constructors: a default constructor that 
    initializes the member variables to their default values, and a constructor 
    with formal parameters that allows you to specify the name and size of the section.

    The sectionType class has several member functions:

    getName and getSize: accessor functions that return the name and size of 
        the section, respectively.

        currently in the section.
    setName and setSize: mutator functions that allow you to change the name 
        and size of the section, respectively.
    list: a function that takes an integer representing the shelf ID and lists 
        the products on that shelf.
    add: a function that takes a string representing a product and adds it to 
        the section.
    remove: a function that takes a string representing a product and removes 
        it from the section.
    removeMany: a function that takes an array of strings representing a list 
        of products and removes them from the section.
    removeAll: a function that removes all products from the section.
    empty: a function that returns a boolean value indicating whether the 
        section is empty or not.

    The sectionType class also has a constant MAX_SIZE representing the maximum 
    number of products that can be stored in the section.
*/
const int MAX_SIZE = 1000;

class sectionType {
private:
    std::string name;
    int size;
    std::string products[MAX_SIZE];
    int numProducts;

public:
    // Default constructor
    sectionType() : name(""), size(10), numProducts(0) {}
    
    // Constructor with formal parameters
    sectionType(std::string name, int size) : name(name), size(size), numProducts(0) {}

    // Accessors
    std::string getName() const { return name; }
    int getSize() const { return size; }
    int getNumProducts() const { return numProducts; }

    // Mutators
    void setName(std::string name) { this->name = name; }
    void setSize(int size) { this->size = size; }

    // List function
    void list(int shelfId) {
        std::cout << "Shelf " << shelfId << " in " << name << " section:" << std::endl;
        for (int i = 0; i < numProducts; i++) {
            std::cout << i+1 << ". " << products[i] << std::endl;
        }
    }

    // Add function
    void add(std::string product) {
        if (numProducts < size) {
            products[numProducts] = product;
            numProducts++;
        } else {
            std::cout << "Error: section is full" << std::endl;
        }
    }

    // Remove function
    void remove(std::string product) {
        for (int i = 0; i < numProducts; i++) {
            if (products[i] == product) {
                for (int j = i; j < numProducts-1; j++) {
                    products[j] = products[j+1];
                }
                numProducts--;
                break;
            }
        }
    }

    // Remove many function
    void removeMany(std::string productsToRemove[], int numProductsToRemove) {
        for (int i = 0; i < numProductsToRemove; i++) {
            remove(productsToRemove[i]);
        }
    }

    // Remove all function
    void removeAll() {
        numProducts = 0;
    }

    // Empty function
    bool empty() {
        return (numProducts == 0);
    }
};

/*
    The trolleyType class represents a trolley used by shoppers in a supermarket. 
    It has the following properties:

    serial: a string representing the serial number of the trolley.
    available: a boolean indicating whether the trolley is available for use or not.
    products: an array of integers representing the products stored in the trolley.
    numProducts: an integer representing the number of products stored in the trolley.

    The class has the following member functions:
    
    Constructors

    trolleyType(): default constructor. Initializes the trolley with an empty serial 
        number and availability set to true.
    trolleyType(std::string serial): parameterized constructor. Initializes the trolley 
        with the given serial number and availability set to true.

    Accessors

    bool isAvailable(): returns true if the trolley is available, false otherwise.
    std::string getSerial(): returns the serial number of the trolley.

    Mutators

    void setAvailability(bool availability): sets the availability of the trolley.
    void addProduct(int id, int quantity): adds the specified quantity of the product 
        with the given id to the trolley. If there is not enough space in the trolley, 
        the function does nothing.
    void removeProduct(int id): removes one instance of the product with the given id 
        from the trolley. If the product is not found in the trolley, the function does nothing.
    void removeAllProducts(): removes all products from the trolley.

    This class can be used to create trolley objects and perform various operations on them, 
    such as checking their availability, setting their availability, adding and removing products, 
    and emptying the trolley
*/

const int MAX_PRODUCTS = 100;

class trolleyType {
private:
    std::string serial;
    bool available;
    int products[MAX_PRODUCTS];
    int numProducts;

public:
    // Default constructor
    trolleyType() {
        serial = "";
        available = true;
        numProducts = 0;
    }

    // Parameterized constructor
    trolleyType(std::string serial) {
        this->serial = serial;
        available = true;
        numProducts = 0;
    }

    // Check if trolley is available
    bool isAvailable() {
        return available;
    }

    // Set trolley availability
    void setAvailability(bool availability) {
        this->available = availability;
    }

    //set new serial to trolley
    void setSerial(std::string new_serial) {
	    this->serial = new_serial;
    }

    // Get trolley serial number
    std::string getSerial() {
        return serial;
    }

    // Add product to trolley
    void addProduct(int id, int quantity) {
        // Check if trolley has space for additional products
        if (numProducts + quantity > MAX_PRODUCTS) {
            // Trolley is full, can't add more products
            return;
        }

        for (int i = 0; i < quantity; i++) {
            products[numProducts] = id;
            numProducts++;
        }
    }

    // Remove product from trolley
    void removeProduct(int id) {
        for (int i = 0; i < numProducts; i++) {
            if (products[i] == id) {
                // Shift all products after the removed product one position to the left
                for (int j = i; j < numProducts - 1; j++) {
                    products[j] = products[j + 1];
                }
                numProducts--;
                return;
            }
        }
    }

    // Remove all products from trolley
    void removeAllProducts() {
        numProducts = 0;
    }
};

/*
    The supermarketType class represents a physical supermarket. 
    It has member variables to store information about the 
    sections in the supermarket and the trolleys available in the 
    trolley section. It also has a number of member functions 
    that allow users to modify and interact with the supermarket 
    object.

    The addSection function adds a new section to the supermarket. 
    The removeSection function removes an existing section from the 
        supermarket, provided that the section is empty. 
    The removeProduct and addProduct functions allow users to 
        remove and add products to sections in the supermarket, 
        respectively. 
    The listProducts function lists all products in a given section, 
    The chooseSection function allows users to select a particular 
        section. 
    The listSections function lists all existing sections in the 
        supermarket.

    The class has a constructor that initializes the trolley section 
    with 10 trolleys. 
    It also has a private member function, getSection, which returns 
    a reference to the section with the given name.

    Overall, the supermarketType class provides a convenient way 
    to represent and interact with a physical supermarket 
    in a program.
*/

//int const MAX_SECTIONS = 10;

class supermarketType {
  public:
    supermarketType() {
      numSections = 0;
    }

    void addSection(const std::string& name) {
      if(numSections >= MAX_SECTIONS) {
        std::cout << "Cannot add more sections, the limit is reached" << std::endl;
        return;
      }
      sections[numSections].setName(name);
      numSections++;
    }

    void removeSection(const std::string& name) {
      for (int i = 0; i < numSections; i++) {
        if (sections[i].getName() == name) {
          for(int j = i; j < numSections - 1; j++) {
            sections[j] = sections[j+1];
          }
          numSections--;
          break;
        }
      }
    }

    //list sections function
    void listSections() {
	    for(int i=0; i < numSections;i++) {
		    std::cout<<"section "<<i+1<<" "<<sections[i].getName()<<std::endl;
	    }
         } 

    //add product function
    void addProduct(const std::string Pname, int Snum) {
      sections[Snum].add(Pname);
    }

    //list products function
    void listProducts(int SId) {
	    sections[SId].list(SId+1);
    }
	

  private:
    static const int MAX_SECTIONS = 10;
    sectionType sections[MAX_SECTIONS];
    int numSections;
};


/*
    The supermarketSections struct appears to represent a collection 
    of sections in a supermarket. It has an array of sectionType objects 
    called listOfSections and an integer variable called sectionSize which 
    stores the number of existing sections. The listOfSections array has 
    a fixed size of 10, which means that it can store up to 10 sectionType 
    objects. The sectionSize variable keeps track of the actual number of 
    sections that have been added to the listOfSections array.

    You can use this struct to store and manage a collection of sections 
    in a supermarket. For example, you can use the sectionSize variable 
    to keep track of the current number of sections and use the 
    listOfSections array to access individual sections. You can also use 
    the listOfSections array to iterate over all existing sections in 
    the collection.

    Note that this is just one possible way to represent a collection of 
    sections in a supermarket, and you may need to modify the struct to 
    meet the specific requirements of your program.
*/

struct supermarketSections {
    // an array of section objects in a supermarket
    sectionType listOfSections[10];

    // the number of existing sections
    int sectionSize = 0;
};




int main() {
    
    //---------------- Start your supermarket  business --------------------------

    // Create a supermarket
    	supermarketType supermarket1;
    
    // Add two sections to the supermarket 
	supermarket1.addSection("Frozen");
	supermarket1.addSection("Fruits and Vegetables");

    // Add 5 products to each section 
	supermarket1.addProduct("Frozen Pizza",0);
	supermarket1.addProduct("Chicken Breast",0);
	supermarket1.addProduct("Frozen Corn",0);
	supermarket1.addProduct("Chicken Burger",0);
	supermarket1.addProduct("Beef Burger",0);

	supermarket1.addProduct("Tomato",1);
	supermarket1.addProduct("Potato",1);
	supermarket1.addProduct("Lettuce",1);
	supermarket1.addProduct("Lemon",1);
	supermarket1.addProduct("Onion",1);
    
    // List sections in your supermarket
	supermarket1.listSections();
	std::cout<<std::endl;

    // list products in each section in the supermarket
	supermarket1.listProducts(0);
	std::cout<<std::endl;
	supermarket1.listProducts(1);
	std::cout<<std::endl;

    // -------------- Go shopping in the supermarket -------------------------------

    // Create your trolley section 
	trolleyType trolley_section[10];
    // Add 10 trolleys to the trolly section
    	
    // pick one trolley and add to it one product from each section
	trolley_section[0].addProduct(1,1);
	trolley_section[0].addProduct(2,1);
    // print products in a trolley
    	

    // Happy shopping and good luck with your shopping experience 


    return 0;
}

