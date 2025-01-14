[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Banking System

### Table Of Contents
- [Description](#-Description)
- [Objective](#-Objective)
- [Synopsis](#-synopsis)
- [Class Diagram](#-class-diagram)
- [Pseudocode](#-pseudocode)
- [Design Description](#-design-description)
- [Findings](#-Findings)



### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/project-management.png" width="3%" height="3%"> Description
In this project, we implement the binary tree concept in our banking system for adding, deleting and searching purpose. On the other hand, we also make our system into 2 views which are from user's view and also staff's view. For the user view, user can create a new account or login to their own account and proceed to deposit, withdrawal, transfer and also displaying transaction history function in the user menu page. For the staff view, staff can enter the system to check all the transaction made by users, search for a specific user's transaction detail and delete a transaction. This project can protect the user's account well because user need to key in their id and password once they want to login and use this system.

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/bc7e2df3-d20d-457c-b9fb-e0574b6a740e" width="3%" height="3%"> Objective
The objectives of creating this banking system:
1) To provide a secure and functionable system
2) To implement banking system using binary tree concept
3) Able to display the transaction history from user’s view and from staff’s view.
4) To provide 2 view spots in the system which are from users and from manager.

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/ac62ef65-848d-41a6-97c2-1ff40be8ecd3" width="3%" height="3%"> Synopsis
In this project, our group HSBC decided to complete a simple banking system. We also created the system from 2 view spots which are users and staff. Our purpose is to provide a banking system with the register and login function and can also manage the banking transactions. The concept of a binary tree that we implemented in this project is to manage the user account like adding a node and delete a node. For adding a node, users have to create a node by input their account info such as secure pin, password and account number. For deleting a node, this function can be only used by staff which is to delete the transaction details of a user by key in the reference number of the transaction. For searching a node, the staff can enter the account number that he/she wants to search for its information and it will display the transaction information of the account. Lastly, for the displaying function in this project, users can only view themselves transaction history whereas for the staff, they can display all the user’s transaction’s information as this can make it easier if they want to have a check on transactio


## Design 🎨

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/b7b1299f-ead1-4e66-ad2e-95b901f4f03c" width="3%" height="3%"> Class Diagram

![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Project/image/class%20diagram.JPG)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/8b3596b0-7214-4cc8-b868-9ab2a0314386" width="3%" height="3%"> Pseudocode

![2](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Project/image/p1.JPG)

![3](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Project/image/p2.JPG)

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Project/image/p3.JPG)

![5](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Project/image/p4.JPG)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/clipboard.png" width="4%" height="4%"> Design Description
##### 1. User View
###### a. Insert a new transaction
For inserting a new transaction, we create a member function named insertNode function. The insertNode function checks whether the node is NULL. If the node is NULL, it will create a new transaction node with parameter of acc and return it. If the referenceNumber of the account is less than the referenceNumber of the node, it will set the left node to the referenceNumber of the account. If the referenceNumber of the account is more than the referenceNumber of the node, it will set the right node to the referenceNumber of the account. 

        Transaction* insertNode(Transaction* node, Transaction& acc) {
            if (node == NULL) {
                return new Transaction(acc); 
            }
            if(acc.referenceNumber < node->referenceNumber){
                node->left = insertNode(node->left, acc);
            }
            else if(acc.referenceNumber > node->referenceNumber){
                node->right = insertNode(node->right, acc);
            }

            return node; // Return the updated root of the current subtree
        }

         void insertAccount(Transaction& acc){
            root = insertNode(root, acc);
        }

###### b. View Current Balance
For viewing current balance, we create a get_balance function which allows us to view the current balance of the account. When the user successfully login to the system, it will record the index of the account and set it to targetAcc. This allows the user to correctly get the balance of the account.

        float get_balance()
        {
            return balance;
        }


###### c. Display own transaction history
For displaying all the transactions of the account, we create a member function named searchAccount function. This function will check whether there is a transaction inside. If there is, it will print all the transaction details

	void printDetails(){
                        cout << setw(7) << referenceNumber;
	            cout <<"             ";        
		cout <<account_number<<"  " 
		     <<setw(19)<<transaction_date << "        "
		     <<transaction_type;
			
		if(transaction_type == "DEPOSIT")
		     cout << "   ";
		else if(transaction_type == "TRANSFER")
		      cout << "  ";
				
	            cout<<setw(13)<<transaction_amount
		    <<"                 "<<target_account<<endl;
		}

        void searchNode(Transaction* node, string& accNum, vector<Transaction*>& result){
            if(node == NULL){
                return;
            }
            
            if(node->account_number == accNum){
                result.push_back(node);
            }

            searchNode(node->left, accNum, result);
            searchNode(node->right, accNum, result);
        }
        
        void searchAccount(string accNum){
            vector<Transaction*> result;
            searchNode(root, accNum, result);
            printTitle();

            if(!result.empty())
            {
                cout << "Found Account with number " << accNum << ":\n";

                for(const auto& node : result){
                    node->printDetails();
                }
            }
            else{
                cout << "No Account found with number " << accNum << "\n";
            }
        }

        
##### 2. Staff View
###### a. Search a transaction by account number
For searching a transaction by account number, it will first search the account number and display the transaction related to the account number. For searching the account number, we created a function called searchAccount function. It takes the accNum parameter and searches for the account number. If the account number is true, it will display all the transactions that are related to the account number that has been entered. If the account number is not true, the system will display an error message which indicates that the account number is not inside the system.

	void printDetails(){
                        cout << setw(7) << referenceNumber;
	            cout <<"             ";        
		cout <<account_number<<"  " 
		     <<setw(19)<<transaction_date << "        "
		     <<transaction_type;
			
		if(transaction_type == "DEPOSIT")
		     cout << "   ";
		else if(transaction_type == "TRANSFER")
		      cout << "  ";
				
	            cout<<setw(13)<<transaction_amount
		    <<"                 "<<target_account<<endl;
		}

        void searchNode(Transaction* node, string& accNum, vector<Transaction*>& result){
            if(node == NULL){
                return;
            }
            
            if(node->account_number == accNum){
                result.push_back(node);
            }

            searchNode(node->left, accNum, result);
            searchNode(node->right, accNum, result);
        }
        
        void searchAccount(string accNum){
            vector<Transaction*> result;
            searchNode(root, accNum, result);
            printTitle();

            if(!result.empty())
            {
                cout << "Found Account with number " << accNum << ":\n";

                for(const auto& node : result){
                    node->printDetails();
                }
            }
            else{
                cout << "No Account found with number " << accNum << "\n";
            }
        }

###### b. Displaying all the transaction
For displaying all the transactions that occurred in this system, we create a member function inside the class which is called displayAccount function. Inside this function, it will call a function that is named as displayInOrder. displayInOrder function checks whether the node is NULL. If it is not NULL, it recursively calls the left node to ensure the left subtree is traversed first. After that, it will print all the details of the node. For displayInOrder(node->right), this is to allow the right subtree to traverse at last. By doing all this, all the transactions that are relevant will be printed out and displayed when the user wants to display all the transactions.

        void displayInOrder(Transaction* node){
            if(node != NULL) {
                displayInOrder(node->left);
                node->printDetails();
                displayInOrder(node->right);
            }
        }

###### c. Delete a transaction
For deleting a transaction, we create a function called deleteAccount function. Inside the function, it will call a function named deleteNode. The deleteNode has 2 parameters which are root and refer. Inside the deleteNode function, it checks whether the node is NULL. If it is NULL, it will return the original node. If the reference number is smaller than the node of referenceNumber, it will start searching at the left subtree. If the reference number is larger than the node of referenceNumber, it will start searching at the right subtree. If the node has one child or no children, it will verify whether the left child is NULL. If it is null, we create a new node pointer which is named temp and it is assigned to the right child. After that, we delete the node which is wanted to be deleted and return the temp pointer. Else, if the right child is NULL, we create a temp pointer that is assigned to the left child. We delete the node and return the temp pointer. For conditions such as the node has two children. We create a temp pointer which is assigned to the minimum value at the right children and we assign the node of referenceNumber is equal to the temp node of the referenceNumber and the right child is equal to the deleteNode function. Lastly, we return the node. For the transactionFile_update function, it updates the text file and removes the information of the node that has been deleted.

        Transaction* deleteNode(Transaction* node, int& refer){
            //case 1: if the node is null
            if (node == NULL)   
                return node;
            
            //case 2: small the go left subtree
            if(refer < node->referenceNumber){
                node->left = deleteNode(node->left, refer);
            }
            //case 3: larger then go right subtree
            else if(refer > node->referenceNumber){
                node->right = deleteNode(node->right, refer);
            }
            //case 4: current node == acc that want to be deleted
            else{
                //case 4.1: if the node has one child or no child
                if(node->left == NULL){
                    Transaction* temp = node->right;
                    delete node;
                    return temp;
                }
                else if(node->right == NULL){
                    Transaction* temp = node->left;
                    delete node;
                    return temp;
                }

                //case 4.2: if the node has two child
                Transaction* temp = findMinValueNode(node->right);
                node->referenceNumber = temp->referenceNumber;
                node->right = deleteNode(node->right, temp->referenceNumber);
            }

            return node;
        }
        
        void deleteAccount(int& refer){
            root = deleteNode(root, refer);
        }



### Prepared by 🧑‍💻

| Name             | Matric Number | Photo                                                         |
| :---------------- | :-------------: | :------------------------------------------------------------: |
|  Hayden Huan Kee Jiun |    A22EC0166     | <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Project/image/photo_2023-12-11_08-21-15%20(1).jpg" title="Icon by Trazobanana"><img src="image/photo_2023-12-11_08-21-15%20(1).jpg" width=80px, height=80px>     |
|   Liow Chee Suan   |   A22EC0072      | <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Project/image/IMG_20231220_173159%20(1).jpg" title="Icon by Trazobanana"><img src="image/IMG_20231220_173159%20(1).jpg" width=80px, height=80px>         |
|  Chan Qing Yee     |   A22EC0040      | <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Project/image/profilepic900kb.jpg" title="Icon by Trazobanana"><img src="image/profilepic900kb.jpg" width=80px, height=80px>         |
|  Ooi Wei Sian     |   A22EC0102      | <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Project/image/weisian.jpg" title="Icon by Trazobanana"><img src="image/weisian.jpg" width=80px, height=80px>         |

### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/folder.png" width="3%" height="3%"> Findings 


- [Assignment 1](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec04/Group%20HSBC/Assignment1)
- [Assignment 2](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec04/Group%20HSBC/Assignment%202)
- [Project](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec04/Group%20HSBC/Project)

### Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)

