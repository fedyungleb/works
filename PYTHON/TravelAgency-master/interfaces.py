import utils
import sys


def main_menu():
    choice = input("Welcome to the Travel Agency service system!\n"
                   "Enter the number of the option you are interested in:\n"
                    "1. I am a customer\n"
                    "2. I am an employee\n"
                    "3. Exit the program \n")

    if choice == "1":
        client_interface()
    elif choice == "2":
        employee_interface()
    elif choice == "3":
        sys.exit()


def client_interface():
    choice = input("Select:\n"
                    "1. View available tours\n"
                    "2. View my details\n"
                    "3. Back to main menu\n"
                   )
    if choice == "1":
        utils.show_offers()
    elif choice == "2":
        id_ = input("Enter your ID number:\n")
        utils.show_your_info(id_)
    elif choice == "3":
        main_menu()
    print()
    client_interface()


def employee_interface():
    choice = input("Select:\n"
                    "1. Manage tours\n"
                    "2. Manage customer data\n"
                    "3. Back to main menu\n")

    if choice == "1":
        manage_offers()
    elif choice == "2":
        manage_client_info()
    elif choice == "3":
        main_menu()
    employee_interface()


def manage_offers():
    choice = input("Select:\n"
                    "1. View available offers\n"
                    "2. Delete the offer\n")
    if choice == "1":
        utils.show_offers()
    elif choice == "2":
        utils.delete_offer()


def manage_client_info():
    choice = input("Select:\n"
                    "1. View customer details\n"
                    "2. Add new client\n"
                    "3. Remove client\n")
    if choice == "1":
        utils.show_client_info()
    elif choice == "2":
        utils.add_client()
    elif choice == "3":
        utils.delete_client()


