#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure definitions
typedef struct {
    int id;
    char name[50];
    char phone[15];
    char email[50];
} Customer;

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

typedef struct {
    int billId;
    int customerId;
    char customerName[50];
    char date[20];
    float totalAmount;
    int numItems;
} Bill;

typedef struct {
    int productId;
    char productName[50];
    int quantity;
    float price;
    float amount;
} BillItem;

// Function prototypes
void displayMenu();
void addCustomer();
void viewCustomers();
void addProduct();
void viewProducts();
void generateBill();
void viewBills();
int getNextCustomerId();
int getNextProductId();
int getNextBillId();
Customer findCustomerById(int id);
Product findProductById(int id);
void updateProductQuantity(int id, int quantity);
void getCurrentDate(char *date);

// File names
#define CUSTOMER_FILE "customers.dat"
#define PRODUCT_FILE "products.dat"
#define BILL_FILE "bills.dat"
#define BILL_ITEMS_FILE "bill_items.dat"

int main() {
    int choice;
    
    printf("\n========================================\n");
    printf("   CUSTOMER BILLING SYSTEM\n");
    printf("========================================\n");
    
    while(1) {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                viewCustomers();
                break;
            case 3:
                addProduct();
                break;
            case 4:
                viewProducts();
                break;
            case 5:
                generateBill();
                break;
            case 6:
                viewBills();
                break;
            case 7:
                printf("\nThank you for using the Billing System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n========================================\n");
    printf("             MAIN MENU\n");
    printf("========================================\n");
    printf("1. Add Customer\n");
    printf("2. View All Customers\n");
    printf("3. Add Product\n");
    printf("4. View All Products\n");
    printf("5. Generate Bill\n");
    printf("6. View All Bills\n");
    printf("7. Exit\n");
    printf("========================================\n");
}

void addCustomer() {
    Customer c;
    FILE *fp;
    
    c.id = getNextCustomerId();
    
    printf("\n--- Add New Customer ---\n");
    printf("Customer ID: %d\n", c.id);
    
    getchar(); // Clear buffer
    printf("Enter Name: ");
    fgets(c.name, 50, stdin);
    c.name[strcspn(c.name, "\n")] = 0; // Remove newline
    
    printf("Enter Phone: ");
    fgets(c.phone, 15, stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;
    
    printf("Enter Email: ");
    fgets(c.email, 50, stdin);
    c.email[strcspn(c.email, "\n")] = 0;
    
    fp = fopen(CUSTOMER_FILE, "ab");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    fwrite(&c, sizeof(Customer), 1, fp);
    fclose(fp);
    
    printf("\nCustomer added successfully!\n");
}

void viewCustomers() {
    Customer c;
    FILE *fp;
    
    fp = fopen(CUSTOMER_FILE, "rb");
    if(fp == NULL) {
        printf("\nNo customers found!\n");
        return;
    }
    
    printf("\n========================================\n");
    printf("           CUSTOMER LIST\n");
    printf("========================================\n");
    printf("%-5s %-20s %-15s %-25s\n", "ID", "Name", "Phone", "Email");
    printf("----------------------------------------\n");
    
    while(fread(&c, sizeof(Customer), 1, fp)) {
        printf("%-5d %-20s %-15s %-25s\n", c.id, c.name, c.phone, c.email);
    }
    
    fclose(fp);
}

void addProduct() {
    Product p;
    FILE *fp;
    
    p.id = getNextProductId();
    
    printf("\n--- Add New Product ---\n");
    printf("Product ID: %d\n", p.id);
    
    getchar(); // Clear buffer
    printf("Enter Product Name: ");
    fgets(p.name, 50, stdin);
    p.name[strcspn(p.name, "\n")] = 0;
    
    printf("Enter Price: ");
    scanf("%f", &p.price);
    
    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    
    fp = fopen(PRODUCT_FILE, "ab");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    fwrite(&p, sizeof(Product), 1, fp);
    fclose(fp);
    
    printf("\nProduct added successfully!\n");
}

void viewProducts() {
    Product p;
    FILE *fp;
    
    fp = fopen(PRODUCT_FILE, "rb");
    if(fp == NULL) {
        printf("\nNo products found!\n");
        return;
    }
    
    printf("\n========================================\n");
    printf("           PRODUCT LIST\n");
    printf("========================================\n");
    printf("%-5s %-25s %-10s %-10s\n", "ID", "Name", "Price", "Stock");
    printf("----------------------------------------\n");
    
    while(fread(&p, sizeof(Product), 1, fp)) {
        printf("%-5d %-25s %-10.2f %-10d\n", p.id, p.name, p.price, p.quantity);
    }
    
    fclose(fp);
}

void generateBill() {
    Bill bill;
    BillItem item;
    FILE *fp, *itemFp;
    int customerId, productId, quantity, numItems;
    char more;
    Customer customer;
    Product product;
    float totalAmount = 0;
    
    bill.billId = getNextBillId();
    
    printf("\n--- Generate Bill ---\n");
    printf("Bill ID: %d\n", bill.billId);
    
    printf("Enter Customer ID: ");
    scanf("%d", &customerId);
    
    customer = findCustomerById(customerId);
    if(customer.id == -1) {
        printf("Customer not found!\n");
        return;
    }
    
    bill.customerId = customer.id;
    strcpy(bill.customerName, customer.name);
    getCurrentDate(bill.date);
    
    printf("\n========================================\n");
    printf("Customer: %s\n", customer.name);
    printf("Date: %s\n", bill.date);
    printf("========================================\n");
    
    numItems = 0;
    itemFp = fopen(BILL_ITEMS_FILE, "ab");
    
    do {
        printf("\nEnter Product ID: ");
        scanf("%d", &productId);
        
        product = findProductById(productId);
        if(product.id == -1) {
            printf("Product not found!\n");
            continue;
        }
        
        printf("Enter Quantity: ");
        scanf("%d", &quantity);
        
        if(quantity > product.quantity) {
            printf("Insufficient stock! Available: %d\n", product.quantity);
            continue;
        }
        
        item.productId = product.id;
        strcpy(item.productName, product.name);
        item.quantity = quantity;
        item.price = product.price;
        item.amount = quantity * product.price;
        
        fwrite(&item, sizeof(BillItem), 1, itemFp);
        
        updateProductQuantity(product.id, product.quantity - quantity);
        
        totalAmount += item.amount;
        numItems++;
        
        printf("\nAdded: %s x %d = %.2f\n", product.name, quantity, item.amount);
        
        printf("Add more items? (y/n): ");
        scanf(" %c", &more);
        
    } while(more == 'y' || more == 'Y');
    
    fclose(itemFp);
    
    bill.totalAmount = totalAmount;
    bill.numItems = numItems;
    
    fp = fopen(BILL_FILE, "ab");
    fwrite(&bill, sizeof(Bill), 1, fp);
    fclose(fp);
    
    // Print Receipt
    printf("\n========================================\n");
    printf("              INVOICE\n");
    printf("========================================\n");
    printf("Bill ID: %d\n", bill.billId);
    printf("Customer: %s\n", bill.customerName);
    printf("Date: %s\n", bill.date);
    printf("========================================\n");
    printf("%-25s %-5s %-10s %-10s\n", "Product", "Qty", "Price", "Amount");
    printf("----------------------------------------\n");
    
    itemFp = fopen(BILL_ITEMS_FILE, "rb");
    fseek(itemFp, -numItems * sizeof(BillItem), SEEK_END);
    
    for(int i = 0; i < numItems; i++) {
        fread(&item, sizeof(BillItem), 1, itemFp);
        printf("%-25s %-5d %-10.2f %-10.2f\n", 
               item.productName, item.quantity, item.price, item.amount);
    }
    
    fclose(itemFp);
    
    printf("========================================\n");
    printf("TOTAL AMOUNT: %.2f\n", bill.totalAmount);
    printf("========================================\n");
    printf("\nBill generated successfully!\n");
}

void viewBills() {
    Bill bill;
    FILE *fp;
    
    fp = fopen(BILL_FILE, "rb");
    if(fp == NULL) {
        printf("\nNo bills found!\n");
        return;
    }
    
    printf("\n========================================\n");
    printf("             BILL HISTORY\n");
    printf("========================================\n");
    printf("%-8s %-20s %-12s %-10s\n", "Bill ID", "Customer", "Date", "Amount");
    printf("----------------------------------------\n");
    
    while(fread(&bill, sizeof(Bill), 1, fp)) {
        printf("%-8d %-20s %-12s %-10.2f\n", 
               bill.billId, bill.customerName, bill.date, bill.totalAmount);
    }
    
    fclose(fp);
}

int getNextCustomerId() {
    Customer c;
    FILE *fp;
    int maxId = 0;
    
    fp = fopen(CUSTOMER_FILE, "rb");
    if(fp == NULL) return 1;
    
    while(fread(&c, sizeof(Customer), 1, fp)) {
        if(c.id > maxId) maxId = c.id;
    }
    
    fclose(fp);
    return maxId + 1;
}

int getNextProductId() {
    Product p;
    FILE *fp;
    int maxId = 0;
    
    fp = fopen(PRODUCT_FILE, "rb");
    if(fp == NULL) return 1;
    
    while(fread(&p, sizeof(Product), 1, fp)) {
        if(p.id > maxId) maxId = p.id;
    }
    
    fclose(fp);
    return maxId + 1;
}

int getNextBillId() {
    Bill b;
    FILE *fp;
    int maxId = 0;
    
    fp = fopen(BILL_FILE, "rb");
    if(fp == NULL) return 1;
    
    while(fread(&b, sizeof(Bill), 1, fp)) {
        if(b.billId > maxId) maxId = b.billId;
    }
    
    fclose(fp);
    return maxId + 1;
}

Customer findCustomerById(int id) {
    Customer c;
    FILE *fp;
    
    c.id = -1; // Not found indicator
    
    fp = fopen(CUSTOMER_FILE, "rb");
    if(fp == NULL) return c;
    
    while(fread(&c, sizeof(Customer), 1, fp)) {
        if(c.id == id) {
            fclose(fp);
            return c;
        }
    }
    
    fclose(fp);
    c.id = -1;
    return c;
}

Product findProductById(int id) {
    Product p;
    FILE *fp;
    
    p.id = -1; // Not found indicator
    
    fp = fopen(PRODUCT_FILE, "rb");
    if(fp == NULL) return p;
    
    while(fread(&p, sizeof(Product), 1, fp)) {
        if(p.id == id) {
            fclose(fp);
            return p;
        }
    }
    
    fclose(fp);
    p.id = -1;
    return p;
}

void updateProductQuantity(int id, int newQuantity) {
    Product p;
    FILE *fp, *tempFp;
    
    fp = fopen(PRODUCT_FILE, "rb");
    tempFp = fopen("temp.dat", "wb");
    
    if(fp == NULL || tempFp == NULL) return;
    
    while(fread(&p, sizeof(Product), 1, fp)) {
        if(p.id == id) {
            p.quantity = newQuantity;
        }
        fwrite(&p, sizeof(Product), 1, tempFp);
    }
    
    fclose(fp);
    fclose(tempFp);
    
    remove(PRODUCT_FILE);
    rename("temp.dat", PRODUCT_FILE);
}

void getCurrentDate(char *date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}
