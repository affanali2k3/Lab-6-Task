#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Officer
{
    private:
        static int count;
        int id;
        string name, rank;
    public:
        Officer()
        {
            count++;
        }

        void setter()
        {
            cout << "Enter id\n";
            cin >> id;
            cin.ignore();
            cout << "Enter name\n";
            getline(cin, name);
            cout << "Enter rank\n";
            getline(cin, name);
        }

        bool isPalindrome()
        {
            bool palindrome = true;
            int mod1 = 10, div1 = 1,len=0;
            while(div1 < id)
            {
                div1*=10;
                len++;
            }

            div1 = 1;
            int mod2 = pow(10, len);
            int div2 = pow(10, len-1);

            while(div1 < id)
            {
                int digit1 = (id%mod1)/div1;
                int digit2 = (id%mod2)/div2;

                mod1 *= 10;
                div1 *=10;

                mod2 /=10;
                div2 /= 10;

                if(digit1 != digit2)
                {
                    palindrome = false;
                    break;
                }
           }

           return palindrome;
        }

        static void getCount()
        {
            cout << "Officers are " << count << endl;
        }
        ~Officer()
        {
            count--;
        }
};

int Officer::count = 0;

int main()
{
    int size = 0;
    Officer *ofr = new Officer [size];
    int choice, i = 0;

    while(1)
    {
        cout << "1.Enter id\n2.Get total number of officers\n3.Exit\n\nChoose: ";
        cin >> choice;
        
        if(choice == 1)
        {
            size++;
            Officer *temp = new Officer[size];
            for(int j = 0; j < size-1; j++)
            {
                temp[j] = ofr[j];
            }
            delete [] ofr;
            ofr = temp;
            temp = nullptr;
            ofr[i].setter();
            if(ofr[i].isPalindrome())
                cout << "Officer is not allowed inside\n";
            else
                cout << "Officer is allowed inside\n";
            i++;
        }
        else if(choice == 2)
            Officer::getCount();
        else if(choice == 3)
            return 0;
        else
            cout << "Invalid option\n";
    }
    return 0;
}
