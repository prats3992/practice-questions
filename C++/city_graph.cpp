#include <iostream>
#include <string>

using namespace std;

// A City Ξ a node in the graph
class City
{
public:
    string city_name;
    City *next; // Pointer to the next city in the list

    // Constructor given name and a null next pointer
    City(string name)
    {
        city_name = name;
        next = NULL;
    }
};

// To represent the graph
class Graph
{
public:
    City *head; // Pointer to the head node of the city list

    // Constructor to initialize the graph with a null head pointer
    Graph()
    {
        head = NULL;
    }

    // Delete all the nodes
    ~Graph()
    {
        City *current = head;
        while (current != NULL)
        {
            City *next = current->next;
            delete current;
            current = next;
        }
    }

    // Remove a city from the city list along with all its connections from the graph
    void remove_city(string name)
    {
        City *current = head;
        City *previous = NULL;

        while (current != NULL)
        {
            if (current->city_name == name)
            {
                // Remove all connections to this city
                City *connecting_city = current->next;
                while (connecting_city != NULL)
                {
                    remove_connection(name, connecting_city->city_name);
                    connecting_city = connecting_city->next;
                }

                // Remove the city node from the graph
                if (previous == NULL)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                delete current;

                return;
            }
            previous = current;
            current = current->next;
        }
    }
    // Add a new city to the end of the city list
    void add_city(string name)
    {
        if (name.empty())
        {
            throw std::invalid_argument("City name cannot be empty.");
        }

        if (find_city(name) != NULL)
        {
            throw std::invalid_argument("City already exists in the graph.");
        }

        if (head == NULL)
        {
            head = new City(name);
        }
        else
        {
            City *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new City(name);
        }
    }

    // Add a new connection between two cities in the graph
    void add_connection(string name1, string name2)
    {
        City *city1 = find_city(name1);
        City *city2 = find_city(name2);

        if (city1 == NULL || city2 == NULL)
        {
            throw std::invalid_argument("One or both cities do not exist in the graph.");
        }

        // Check if the connection already exists
        City *connecting_city = city1->next;
        while (connecting_city != NULL)
        {
            if (connecting_city->city_name == name2)
            {
                throw std::invalid_argument("Connection already exists between the two cities.");
            }
            connecting_city = connecting_city->next;
        }

        // Add city2 to the end of the connecting_city list of city1
        City *current = city1;
        while (current->next != NULL)
        {
            if (current->city_name == name2)
            {
                throw std::invalid_argument("Connection already exists between the two cities.");
            }
            current = current->next;
        }
        current->next = city2;

        // Add city1 to the end of the connecting_city list of city2
        current = city2;
        while (current->next != NULL)
        {
            if (current->city_name == name1)
            {
                throw std::invalid_argument("Connection already exists between the two cities.");
            }
            current = current->next;
        }
        current->next = city1;
    }

    // Remove a connection between two cities in the graph
    void remove_connection(string name1, string name2)
    {
        City *city1 = find_city(name1);
        City *city2 = find_city(name2);

        if (city1 == NULL || city2 == NULL)
        {
            throw std::invalid_argument("One or both cities do not exist in the graph.");
        }

        // Find city2 in the connecting_city list of city1 and remove it
        City *current = city1;
        City *previous = NULL;

        while (current != NULL)
        {
            if (current == city2)
            {
                if (previous == NULL)
                {
                    city1->next = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                return;
            }
            previous = current;
            current = current->next;
        }

        // If the connection does not exist, throw an exception
        throw std::invalid_argument("Connection does not exist between the two cities.");
    }

private:
    City *find_city(string name)
    {
        City *current = head;
        while (current != NULL)
        {
            if (current->city_name == name)
            {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
};

int main()
{
    Graph city;
    int invalid_counter = 0;
    while (true && invalid_counter < 5)
    {
        cout << "Hi, choose an option from below:\n";
        cout << "1. Create Graph\n2. Add City\n3. Remove City\n4. Add Connection\n5. Remove Connection\n6. Exit\n";
        cout << "Enter Choice Number: ";
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << "Air Traffic Graph Created" << endl;
            cout << "Enter Number of Cities to be added on Creation: ";
            int numy;
            cin >> numy;
            for (int i = 0; i < numy; i++)
            {
                string cities;
                cout << "Enter City: ";
                cin >> cities;
                city.add_city(cities);
            }
        }
        else if (x == 2)
        {
            cout << "Enter City to Add: ";
            string new_city;
            cin >> new_city;
            city.add_city(new_city);
        }
        else if (x == 3)
        {
            cout << "Enter City to Remove: ";
            string city_name;
            cin >> city_name;
            city.remove_city(city_name);
        }
        else if (x == 4)
        {
            cout << "Enter Source City: ";
            string src;
            cin >> src;
            cout << "Enter Destination City: ";
            string dest;
            cin >> dest;
            city.add_connection(src, dest);
        }
        else if (x == 5)
        {
            cout << "Enter Source City: ";
            string src;
            cin >> src;
            cout << "Enter Destination City: ";
            string dest;
            cin >> dest;
            city.remove_connection(src, dest);
        }
        else if (x == 6)
        {
            cout << "Goodbye!" << endl;
            return 0;
        }
        else
        {
            cout << "Invalid Choice. Try Again." << endl;
            invalid_counter++;
        }
    }
    cout << "Too many invalid choices. Exiting." << endl;
    return 0;
}
