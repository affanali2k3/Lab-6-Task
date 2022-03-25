#include <iostream>
#include <string>
using namespace std;

class Person
{
    private:
        char userData[100];
    
    friend class Coordinator;
 
};

class Coordinator
{
    private:
    
    public:
        Person p1,p2;
        void setter()
        {
            cout << "Enter competetion and universty of Person 1\n";
            cin.getline(p1.userData, 100);

            cout << "Enter competetion and universty of Person 2\n";
            cin.getline(p2.userData, 100);
        }

        int roomNumber()
        {
            int i=0,j=0;
            while(p1.userData[i] != ' ')
                i++;

            while(p2.userData[j]!=' ')
                j++;

            if(i > j)
                return i;
            else
                return j;
        }

        string getUniverstyName(Person p)
        {
            int i=0,j = 0;
            while(p.userData[i] != '\0')
            {
                if(p.userData[i] == ' ')
                {
                    i++;
                    while(p.userData[i] != '\0')
                    {
                        p.userData[j] = p.userData[i];
                        i++;
                        j++;
                    }
                    break;
                }
                i++;
            }
            p.userData[j] = '\0';
            return p.userData;
        }

        void allotRoom()
        {
            string uniPerson1 = getUniverstyName(p1);
            string uniPerson2 = getUniverstyName(p2);

            if(uniPerson1 == uniPerson2)
            {
                int room = roomNumber();
                cout << "Person 1 and Person 2 are alloted room number " << room << endl;
            }
            else
            {
                cout << "Person 1 and Person 2 are not roommates\n";
            }
        }

};

int main()
{
    Coordinator c;
    c.setter();
    c.allotRoom();
    return 0;
}