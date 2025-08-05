#include<bits/stdc++.h>
#include <string>
#include<fstream>
#include<iomanip>
#include "header.h"
#define FLBSTUD "student.txt"
#define FLBGRAD "grade.txt"
using namespace std;
fstream fil;
int w;
char ch;
class Student
{
	char studentName[30];
	string name;
	string btID;
	int rollNo;
	char gender[4];
	char course[10];
	char branch[10];
	int classop1;
	int ABCid;
	int phoneNo;
	char fatherName[30];
	char motherName[30];
	char address[80];
	
public:
    //Default Constructor
    Student(){};
    // Constructor to initialize student details
    Student(string btID, string name) : btID(btID), name(name) {}

    // Getter methods
    string getBtID() const { return btID; }
    string getName() const { return name; }

	void getDetails();

	void printDetails()
{
	cout << "Student Name  : " << studentName << endl;
	cout << "Roll No.      : " << rollNo << endl;
	cout << "Gender        : " << gender << endl;
	cout << "Course        : " << course << endl;
	cout << "Branch        : " << branch << endl;
	cout << "ABC ID        : " << ABCid << endl;
	cout << "Phone Number  : " << phoneNo << endl;
	cout << "Father's Name : " << fatherName << endl;
	cout << "Mother's Name : " << motherName << endl;
	cout << "Address       : " << address << endl;
	
}

	int retRollNo() {				//Return Roll No
		return rollNo;
	}
	
	char* retStudentName() {		//Returns Student Name
		return studentName;
	}
};


void Student::getDetails()
{
	CLS();
	cout << "Enter Student's Name        : ";
	do {
		gets(studentName);
	} while (strlen(studentName) == 0);

	cout << "Enter Roll No.              : ";
	do {
		cin>>rollNo;
	} while (rollNo == 0);
	cout << "Enter Gender [M/F]          : ";
	do {
		gets(gender);
	} while (strlen(gender) == 0);

	cout << "Enter Course                : ";
	do {
		gets(course);
	} while (strlen(course) == 0);

	cout << "Enter Branch                : ";
	do {
		gets(branch);
	} while (strlen(branch) == 0);

	cout << "Enter ABC ID                : ";
	do {
		ABCid = scan();
	} while (ABCid == 0);

	cout << "Enter Phone No.             : ";
	do {
		phoneNo = scan();
	} while (phoneNo == 0);
	cout << "Enter Father's Name         : ";
	do {
		gets(fatherName);
	} while (strlen(fatherName) == 0);

	cout << "Enter Mother's Name         : ";
	do {
		gets(motherName);
	} while (strlen(motherName) == 0);

	cout << "Enter Address               : ";
	do {
		gets(address);
	} while (strlen(address) == 0);

}


void insertStudent()			//Insert Student Record in File
{
	CLS();
	Student obj, obj2;
	char ch;
	int v = 0;
	cout << "Enter Details for new Student :\n";
	obj.getDetails();
	fstream fl1(FLBSTUD, ios::in );
	ofstream fl2;
	if (!fl1)			//If file does not exist, create new file
	{
		fl2.open(FLBSTUD, ios::out );
		fl2.write((char*)& obj, sizeof(obj));
		fl2.close();
		cout << "Record successfully inserted !\n";
		return;
	}
	while (!fl1.eof())
	{
		fl1.read((char*)& obj2, sizeof(obj));
		if (fl1.eof())
		{
			break;
		}
		if (obj.retRollNo() == obj2.retRollNo())		//If record with same Roll No. exists, then abort insertion
		{
			cout << "Record with same Roll No. with following details already exists : \n";
			obj2.printDetails();
			cout << "Insertion Aborted !\n";
			return;
		}
		else if (strcmpi(obj.retStudentName(), obj2.retStudentName()) == 0)
		{
			if (!v)							//Warns user that Record with same name exists
				cout << "Warning : Record with same name exists with follwing details : \n";
			obj2.printDetails();
			cout << '\n';
			v = 1;
		}
	}
	if (v)
	{
		cout << "Do you still wish to insert record (Y/N) ? ";
		do {									//Asks for user confirmation after warning
			cin >> ch;
			ch = toupper(ch);
		} while (ch != 'Y' && ch != 'N');
		if (ch == 'N') {
			cout << "Insertion Aborted !\n";
			return;
		}
	}
	fl2.open(FLBSTUD, ios::out | ios::app | ios::binary);
	fl2.seekp(0, ios::end);
	fl2.write((char*)& obj, sizeof(obj));
	fl2.close();
	cout << "Record Inserted successfully !\n";
}



void dispStudentRecord()		//Display all Student Records
{
	CLS();
	Student obj;
	int v = 0;
	fstream fl(FLBSTUD, ios::in | ios::binary);
	if (!fl)
	{					//If file does not exist
		cout << "Empty Records !\n";
		return ;
	}
	while (!fl.eof())
	{
		fl.read((char*)& obj, sizeof(obj));
		if (fl.eof())
			break;
		v = 1;
		obj.printDetails();
		cout<<"--------------------------------\n";
	}
	fl.close();
	if (!v)
		cout << "Empty Records !\n";
	return ;
}


int searchByRollNo()
{
	CLS();
	int r;
	int found = 0;
	Student obj;
	cout << "Enter Roll No. to search for : ";
	cin >> r;
	fstream fl(FLBSTUD, ios::in | ios::binary);
	if (!fl) {					//No file exists
		cout << "No Records Found !\n";
	}
	while (!fl.eof())
	{
		fl.read((char*)& obj, sizeof(obj));
		if (fl.eof())
		{
			break;
		}
		if (r == obj.retRollNo())
		{
			if (!found)
				cout << "\nSearch Results : \n\n";

			obj.printDetails();
			RULE('-');
			found = 1;
		}
	}
	if (!found)
		cout << "No Records Found !\n";
	fl.close();
    return found;
}


// void searchByRollNo(int i)
// {
// 	CLS();
// 	int r;
// 	int found = 0;
// 	Student obj;
// 	cout << "Enter Roll No. to search for : ";
// 	cin >> r;
// 	fstream fl(FLBSTUD, ios::in | ios::binary);
// 	if (!fl) {					//No file exists
// 		cout << "No Records Found !\n";
// 		return;
// 	}

    // while (fl.read((char*)& obj, sizeof(obj)))
    // {
    //     if (obj.retRollNo() == r)  // Assuming `rollNo` is a member of `Student`
    //     {
    //         found = 1;
    //         break;
    //     }
    // }
	// while (!fl.eof())
	// {
    //     fl.read((char*)& obj, sizeof(obj));
	// 	if (fl.eof())
	// 		break;

		// if (r == obj.retRollNo())
		// {
		// 	if (!found)
		// 		cout << "\nSearch Results : \n\n";

		// 	obj.printDetails();
        //     cout<<"---------------------";
		// 	// RULE('-');
		// 	found = 1;
		// }
	// }
	// if (!found)
	// 	cout << "No Records Found !\n";
	// fl.close();
	// return;
// }





void delStudentRecord()
{
	CLS();
	Student obj;					//Writes to new file except record to be deleted
	int f = 0;
	cout << "\nEnter Roll No. to delete : ";
	int r;
	char ch;
	cin >> r;
	fstream fl(FLBSTUD, ios::in | ios::binary);
	fstream fo("temp.dat", ios::out | ios::binary);
	while (!fl.eof())
	{
		fl.read((char*)& obj, sizeof(obj));

		if (fl.eof())
			break;

		if (r == obj.retRollNo())
		{
			cout << "Record with following info will be deleted :\n\n";
			obj.printDetails();
			cout << "Do you wish to continue ? (Y/N) : ";
			do {
				cin >> ch;
				ch = toupper(ch);
			} while (ch != 'N' && ch != 'Y');

			if (ch == 'N')
			{
				cout << "Deletion Aborted !\n";
				fl.close();
				fo.close();
				remove("temp.dat");
				return;
			}
			f = 1;
			continue;
		}
		fo.write((char*)& obj, sizeof(obj));
	}
	fl.close();
	fo.close();
	remove(FLBSTUD);
	rename("temp.dat", FLBSTUD);
	if (f)
		cout << "Record Successfully Deleted !\n";
	else
		cout << "No Such Record Exists !\n";
}


class Grade
{
private:
	char  name[30];
	int   rollNo;
	int   total,s1,s2,es;
	float perc;
public:
	int retRollNo()
	{
		return rollNo;
	}
	void retGrade(float marks)
	{
		if (marks < 50)
		{
			printf("Grade F");
		}
		else if (marks >= 50 && marks < 60)
		{
			printf("Grade D");
		}
		else if (marks >= 60 && marks < 70)
		{
			printf("Grade C");
		}
		else if (marks >= 70 && marks < 80)
		{
			printf("Grade B");
		}
		else if (marks >= 80 && marks < 90)
		{
			printf("Grade A");
		}
		else
		{
			printf("Grade A+");
		}
	}
	void getDetails(void);
	void putDetails(void);
};

void Grade::getDetails(void)
{
	cout << "Enter Roll No. : ";
	cin >> rollNo;
	cout << "Enter Full Name: ";
	cin >> name;
	cout << "Enter Sesional 1 Marks (15) : ";
	cin>>s1;
	cout << "Enter Sesional 2 Marks (15) : ";
	cin>>s2;
	cout << "Enter End Semester Marks (70) : ";
	cin>>es;
	total = s1 + s2 + es;
	perc = (float)total /100 * 100;
}

void Grade::putDetails(void)
{
	cout << "Student Name     : " << name << endl;
	cout << "Roll No.         : " << rollNo << endl;
	cout << "Total Marks      : " << total << endl; 
	//cout << "Percentage	 : " << perc << endl;
	cout << "CG               : " << perc/10 << endl;
	retGrade(perc);
}

void insertGrade()			//Insert Grade  in File
{
	system("CLS");
	Grade obj, obj2;
	char ch;
	int v = 0;
	obj.getDetails();
	fstream gl1(FLBGRAD, ios::in | ios::binary);
	ofstream gl2;
	if (!gl1)
	{
		gl2.open(FLBGRAD, ios::out | ios::binary);
		gl2.write((char*)& obj, sizeof(obj));
		gl2.close();
		cout << "Grade successfully inserted !\n";
		return;
	}

	gl2.open(FLBGRAD, ios::out | ios::app | ios::binary);
	gl2.seekp(0, ios::end);
	gl2.write((char*)& obj, sizeof(obj));
	gl2.close();
	cout << "Grade Inserted successfully !\n";
}


void dispGrade()		//Display all Student Records
{
	// system("CLS");
	Grade obj;
	int v = 0;
	fstream fl(FLBGRAD, ios::in | ios::binary);
	if (!fl)
	{					//If file does not exist
		cout << "Empty Records !\n";
		return ;
	}
	while (!fl.eof())
	{
		fl.read((char*)& obj, sizeof(obj));
		if (fl.eof())
			break;
		v = 1;
		obj.putDetails();
		// RULE('-');
	}
	fl.close();
	if (!v)
		cout << "Empty Records !\n";
	return ;
}

int searchGradeByRollNo()
{
	system("CLS");
	int r;
	int found = 0;
	Grade obj;
	cout << "Enter Roll No. to search for : ";
	cin >> r;
	fstream fl(FLBGRAD, ios::in | ios::binary);
	if (!fl) {					//No file exists
		cout << "No Records Found !\n";
		return 0;
	}
	while (!fl.eof())
	{
		fl.read((char*)& obj, sizeof(obj));
		if (fl.eof())
		{
			break;
		}
		if (r == obj.retRollNo())
		{
			if (!found)
				cout << "\nSearch Results : \n\n";

			obj.putDetails();
			RULE('-');
			found = 1;
		}
	}
	if (!found)
		cout << "No Records Found !\n";
	fl.close();
	return found;
}

class ClubMember {
public:
    string cname;
    string name;
    int rollNumber;

    ClubMember(string cname, string name, int rollNumber) : cname(cname), name(name), rollNumber(rollNumber) {}

    void saveToFile(ofstream &out) const {
        out << cname << "," << name << "," << rollNumber << "\n";
    }

    void printDetails() const {
        cout << "Club name: " << cname << ", Name: " << name << ", Roll No: " << rollNumber << endl;
    }
};

class ClubEvent {
public:
    string eventName;
    string date;
    string description;

    ClubEvent(string eventName, string date, string description)
        : eventName(eventName), date(date), description(description) {}

    void saveToFile(ofstream &out) const {
        out << eventName << "," << date << "," << description << "\n";
    }
};

class Club {
public:
    string clubName;
    string clubDescription;
    vector<ClubMember> members;
    vector<ClubEvent> events;

    Club(string name, string description) : clubName(name), clubDescription(description) {
        loadMembersFromFile();
        loadEventsFromFile();
    }

    void addMember(string name, int rollNumber) {
        system("CLS");
        ClubMember member(clubName, name, rollNumber);
        members.push_back(member);
        saveMemberToFile(member);
        cout << "Member " << name << " added successfully.\n";
    }

    void addEvent(string eventName, string date, string description) {
        system("CLS");
        ClubEvent event(eventName, date, description);
        events.push_back(event);
        saveEventToFile(event);
        cout << "Event " << eventName << " scheduled for " << date << ".\n";
    }

    void displayClubs(const vector<Club> &clubs) const {
        system("CLS");
        cout << "Available Clubs:\n";
        for (size_t i = 0; i < clubs.size(); ++i) {
            cout << i + 1 << ". " << clubs[i].clubName << endl;
        }
    }

    void displayMembers() const {
        system("CLS");
        cout << "\n--- Members of " << clubName << " ---\n";
        for (const auto &member : members) {
            member.printDetails();
        }
    }

    void displayEvents() const {
        system("CLS");
        cout << "\n--- Events of " << clubName << " ---\n";
        for (const auto &event : events) {
            cout << "Event: " << event.eventName << ", Date: " << event.date << "\nDescription: " << event.description << "\n";
        }
    }

    bool searchMemberByRollNo(int rollNumber) const {
        system("CLS");
        ifstream inFile("members.txt", ios::binary);
        if (!inFile) {
            cout << "No Records Found!\n";
            return false;
        }

        string cname, name;
        int roll;
        bool found = false;

        while (inFile >> ws && getline(inFile, cname, ',') && getline(inFile, name, ',') && inFile >> roll) {
            if (roll == rollNumber) {
                cout << "\nSearch Results:\n";
                cout << "Club name: " << cname << ", Name: " << name << ", Roll No: " << roll << endl;
                found = true;
                break;
            }
            inFile.ignore();
        }

        if (!found) {
            cout << "No member found with Roll No: " << rollNumber << "\n";
        }

        inFile.close();
        return found;
    }

    void saveToFile(ofstream &out) const {
        out << clubName << "," << clubDescription << "\n";
    }

private:
    void saveMemberToFile(const ClubMember &member) const {
        ofstream out("members.txt", ios::app | ios::binary);
        if (out.is_open()) {
            member.saveToFile(out);
            out.close();
        }
    }

    void saveEventToFile(const ClubEvent &event) const {
        ofstream out("events.txt", ios::app | ios::binary);
        if (out.is_open()) {
            event.saveToFile(out);
            out.close();
        }
    }

    void loadMembersFromFile() {
        ifstream in("members.txt", ios::binary);
        if (in.is_open()) {
            string cname, name;
            int rollNumber;
            while (in >> ws && getline(in, cname, ',') && getline(in, name, ',') && in >> rollNumber) {
                if (cname == clubName) {
                    members.emplace_back(cname, name, rollNumber);
                }
                in.ignore();
            }
            in.close();
        }
    }

    void loadEventsFromFile() {
        ifstream in("events.txt", ios::binary);
        if (in.is_open()) {
            string eventName, date, description;
            while (in >> ws && getline(in, eventName, ',') && getline(in, date, ',') && getline(in, description)) {
                events.emplace_back(eventName, date, description);
            }
            in.close();
        }
    }
};

void loadClubsFromFile(vector<Club> &clubs) {
    ifstream in("clubs.txt", ios::binary);
    if (in.is_open()) {
        string clubName, clubDescription;
        while (getline(in, clubName, ',') && getline(in, clubDescription)) {
            clubs.emplace_back(clubName, clubDescription);
        }
        in.close();
    }
}

void saveClubsToFile(const vector<Club> &clubs) {
    ofstream out("clubs.txt", ios::binary);
    if (out.is_open()) {
        for (const auto &club : clubs) {
            club.saveToFile(out);
        }
        out.close();
    }
}

void clubSection(){
	vector<Club> clubs;
    loadClubsFromFile(clubs);

    int choice;
    do {
        cout << "\n--- Club Management ---\n";
        cout << "1. Create New Club\n2. View All Clubs\n3. Add Member\n4. Add Event\n5. Display Members\n6. Display Events\n7. Search Member by Roll Number\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string clubName, clubDescription;
            cout << "Enter club name: ";
            cin.ignore();
            getline(cin, clubName);
            cout << "Enter club description: ";
            getline(cin, clubDescription);
            clubs.emplace_back(clubName, clubDescription);
            saveClubsToFile(clubs);
            cout << "Club " << clubName << " created successfully.\n";
        } else if (choice == 2) {
            if (clubs.empty()) {
                cout << "No clubs available. Please create a club first.\n";
                continue;
            }
            clubs[0].displayClubs(clubs);
        } else if (choice == 3 || choice == 5) {
            if (clubs.empty()) {
                cout << "No clubs available. Please create a club first.\n";
                continue;
            }

            cout << "Choose a club:\n";
            for (int i = 0; i < clubs.size(); i++) {
                cout << i + 1 << ". " << clubs[i].clubName << endl;
            }
            int clubChoice;
            cout << "Enter your club choice: ";
            cin >> clubChoice;

            Club &selectedClub = clubs[clubChoice - 1];
            if (choice == 3) {
                string name;
                int rollNumber;
                cin.ignore();
                cout << "Enter member name: ";
                getline(cin, name);
                cout << "Enter roll number: ";
                cin >> rollNumber;
                selectedClub.addMember(name, rollNumber);
            } else if (choice == 5) {
                selectedClub.displayMembers();
            }
        } else if (choice == 4) {
            if (clubs.empty()) {
                cout << "No clubs available. Please create a club first.\n";
                continue;
            }

            string eventName, date, description;
            cout << "Enter event name: ";
            cin.ignore();
            getline(cin, eventName);
            cout << "Enter event date: ";
            getline(cin, date);
            cout << "Enter event description: ";
            getline(cin, description);
            clubs[0].addEvent(eventName, date, description);
        } else if (choice == 6) {
            if (clubs.empty()) {
                cout << "No clubs available. Please create a club first.\n";
                continue;
            }
            clubs[0].displayEvents();
        } else if (choice == 7) {
            int rollNumber;
            cout << "Enter roll number: ";
            cin >> rollNumber;

            bool found = false;
            for (const auto &club : clubs) {
                if (club.searchMemberByRollNo(rollNumber)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "No member found with Roll No: " << rollNumber << "\n";
            }
        }
    } while (choice != 8);

}
///////////////////////////////registraion starts//////////////////////////////////////
// class to enter registration data
class registration {
    protected:
    static int paskey;                
    int sem, rollnum, no_ofsub;
    string btid, branch;
    map<string, int> st_login;

public:
    void load_login_data() {
        ifstream infile("login_data.txt");
        string id;
        int pass;
        while (infile >> id >> pass) {
            st_login[id] = pass;
        }
        infile.close();
    }

    void login() {
        cout << "Enter ID: ";
        cin >> btid;
        cout << "Enter your password: ";
        cin >> paskey;
        
        if (st_login.find(btid) != st_login.end() && st_login[btid] == paskey) {
            cout<<"welcome, you are successfully loggedin\n";
            cout<<"enter your branch: ";
            cin>>branch;
            cout << "Enter your semester: ";
            cin >> sem;
            int p;
            cout << "Enter 1 if you have any backlog else enter 0: ";
            cin >> p;
            if (p == 1) {
                backlock();
            }
            if (sem > 0 && sem < 9) {
                semester(sem);
            } else {
                cout << "Semester should be between 1 to 8. Login again to register.\n";
                loginagain();
            }
        } else {
            cout << "Invalid ID or password, please try again.\n";
            loginagain();
        }
    }

    void loginagain() {
        login();
    }

    void backlock() {
        int numr;
        cout << "Enter the number of subjects in which you have a backlog: ";
        cin >> numr;
        if (numr > 3) {
            cout << "You can't cover more than 3 backlog subjects in one semester.\n";
        } else {
            cout << "Select your backlog subjects:\n";
            select_backlog_subjects(numr);
        }
    }
    void select_backlog_subjects(int numr) {
    vector<string> subjects;
    if (branch == "cse") {
        switch (sem) {
            case 1: cout << "You can't have backlog in first semester\n"; 
            return;
            case 2: subjects = {"csl101", "csl102", "csl103", "csl104", "csl105", "csl106"}; 
            break;
            case 3: subjects = {"csl201", "csl202", "csl203", "csl204", "csl205", "csl206"}; 
            break;
            case 4: subjects = {"csl301", "csl302", "csl303", "csl304", "csl305", "csl306"}; 
            break;
            case 5: subjects = {"csl401", "csl402", "csl403", "csl404", "csl405", "csl406"}; 
            break;
            case 6: subjects = {"csl501", "csl502", "csl503", "csl504", "csl505", "csl506"}; 
            break;
            case 7: subjects = {"csl601", "csl602", "csl603", "csl604", "csl605", "csl606"}; 
            break;
            case 8: subjects = {"csl701", "csl702", "csl703", "csl704", "csl705", "csl706"}; 
            break;
            default: cout << "Invalid semester for CSE\n"; 
            return;
        }
    } else if (branch == "ece") {
        switch (sem) {
            case 1: cout << "You can't have backlog in first semester\n"; break;
            case 2: subjects = {"ecl101", "ecl102", "ecl103", "ecl104", "ecl105", "ecl106"}; 
            break;
            case 3: subjects = {"ecl201", "ecl202", "ecl203", "ecl204", "ecl205", "ecl206"}; 
            break;
            case 4: subjects = {"ecl301", "ecl302", "ecl303", "ecl304", "ecl305", "ecl306"}; 
            break;
            case 5: subjects = {"ecl401", "ecl402", "ecl403", "ecl404", "ecl405", "ecl406"}; 
            break;
            case 6: subjects = {"ecl501", "ecl502", "ecl503", "ecl504", "ecl505", "ecl506"}; 
            break;
            case 7: subjects = {"ecl601", "ecl602", "ecl603", "ecl604", "ecl605", "ecl606"}; 
            break;
            case 8: subjects = {"ecl701", "ecl702", "ecl703", "ecl704", "ecl705", "ecl706"};
            break;
            default: cout << "Invalid semester for ECE\n"; 
            return;
        }
    } else if (branch == "eci") {
        switch (sem) {
            case 1: cout << "You can't have backlog in first semester\n"; break;
            case 2: subjects = {"eil101", "eil102", "eil103", "eil104", "eil105", "eil106"}; 
            break;
            case 3: subjects = {"eil201", "eil202", "eil203", "eil204", "eil205", "eil206"}; 
            break;
            case 4: subjects = {"eil301", "eil302", "eil303", "eil304", "eil305", "eil306"}; 
            break;
            case 5: subjects = {"eil401", "eil402", "eil403", "eil404", "eil405", "eil406"}; 
            break;
            case 6: subjects = {"eil501", "eil502", "eil503", "eil504", "eil505", "eil506"}; 
            break;
            case 7: subjects = {"eil601", "eil602", "eil603", "eil604", "eil605", "eil606"}; 
            break;
            case 8: subjects = {"eil701", "eil702", "eil703", "eil704", "eil705", "eil706"}; 
            break;
            default: cout << "Invalid semester for IOT\n"; 
            return;
        }
    }else if (branch == "csd") {
        switch (sem) {
            case 1: cout << "You can't have backlog in first semester\n"; break;
            case 2: subjects = {"cdl101", "cdl102", "cdl103", "cdl104", "cdl105", "cdl106"}; 
            break;
            case 3: subjects = {"cdl201", "cdl202", "cdl203", "cdl204", "cdl205", "cdl206"}; 
            break;
            case 4: subjects = {"cdl301", "cdl302", "cdl303", "cdl304", "cdl305", "cdl306"}; 
            break;
            case 5: subjects = {"cdl401", "cdl402", "cdl403", "cdl404", "cdl405", "cdl406"}; 
            break;
            case 6: subjects = {"cdl501", "cdl502", "cdl503", "cdl504", "cdl505", "cdl506"}; 
            break;
            case 7: subjects = {"cdl601", "cdl602", "cdl603", "cdl604", "cdl605", "cdl606"}; 
            break;
            case 8: subjects = {"cdl701", "cdl702", "cdl703", "cdl704", "cdl705", "cdl706"}; 
            break;
            default: cout << "Invalid semester for CSD\n"; 
            return;
        }
    }else if (branch == "csh") {
        switch (sem) {
            case 1: cout << "You can't have backlog in first semester\n"; break;
            case 2: subjects = {"chl101", "chl102", "chl103", "chl104", "chl105", "chl106"}; 
            break;
            case 3: subjects = {"chl201", "chl202", "chl203", "chl204", "chl205", "chl206"}; 
            break;
            case 4: subjects = {"chl301", "chl302", "chl303", "chl304", "chl305", "chl306"}; 
            break;
            case 5: subjects = {"chl401", "chl402", "chl403", "chl404", "chl405", "chl406"}; 
            break;
            case 6: subjects = {"chl501", "chl502", "chl503", "chl504", "chl505", "chl506"}; 
            break;
            case 7: subjects = {"chl601", "chl602", "chl603", "chl604", "chl605", "chl606"}; 
            break;
            case 8: subjects = {"chl701", "chl702", "chl703", "chl704", "chl705", "chl706"}; 
            break;
            default: cout << "Invalid semester for CSH\n"; 
            return;
        }
    }else{
        cout<<"please enter valid brach \n";
    }
    

    for (int i = 0; i < subjects.size(); ++i) {
        cout << i + 1 << " -> " << subjects[i] << "\n";
    }

    ofstream outfile(branch + to_string(sem) +"_backlog_students.txt", ios::app);
    outfile <<btid <<"   "<< sem <<"          ";
    for (int i = 0; i < numr; ++i) {
        int sub_index;
        cout << "Enter subject index: ";
        cin >> sub_index;
        if (sub_index > 0 && sub_index <= subjects.size()) {
            outfile << subjects[sub_index - 1] << " ";
        } else {
            cout << "Invalid subject selection. Select valid subjects\n";
            --i;
        }
    }
        time_t now = time(0);
        char* dt = ctime(&now);
        outfile << "      " << dt;
    outfile.close();
    cout << "Backlog subjects saved successfully.\n";
}

    void semester(int sem) {
    ofstream outfile(branch + to_string(sem) + "_students.txt", ios::app);
    if (!outfile) {
        cout << "Error opening file: " << branch << "_students.txt" << endl;
        return;
    }

    outfile <<btid <<"   "<< sem <<"          ";
    cout << "Select your 6 subjects by their code\n";

    vector<string> subjects;

    if (branch == "cse") {
        switch (sem) {
            case 1: subjects = {"csl101", "csl102", "csl103", "csl104", "csl105", "csl106"}; 
            break;
            case 2: subjects = {"csl201", "csl202", "csl203", "csl204", "csl205", "csl206"}; 
            break;
            case 3: subjects = {"csl301", "csl302", "csl303", "csl304", "csl305", "csl306"}; 
            break;
            case 4: subjects = {"csl401", "csl402", "csl403", "csl404", "csl405", "csl406"}; 
            break;
            case 5: subjects = {"csl501", "csl502", "csl503", "csl504", "csl505", "csl506"}; 
            break;
            case 6: subjects = {"csl601", "csl602", "csl603", "csl604", "csl605", "csl606"}; 
            break;
            case 7: subjects = {"csl701", "csl702", "csl703", "csl704", "csl705", "csl706"}; 
            break;
            case 8: subjects = {"csl801", "csl802", "csl803", "csl804", "csl805", "csl806"}; 
            break;
            default: cout << "Invalid semester for CSE\n"; 
            return;
        }
    } else if (branch == "ece") {
        switch (sem) {
            case 1: subjects = {"ecl101", "ecl102", "ecl103", "ecl104", "ecl105", "ecl106"}; 
            break;
            case 2: subjects = {"ecl201", "ecl202", "ecl203", "ecl204", "ecl205", "ecl206"}; 
            break;
            case 3: subjects = {"ecl301", "ecl302", "ecl303", "ecl304", "ecl305", "ecl306"}; 
            break;
            case 4: subjects = {"ecl401", "ecl402", "ecl403", "ecl404", "ecl405", "ecl406"}; 
            break;
            case 5: subjects = {"ecl501", "ecl502", "ecl503", "ecl504", "ecl505", "ecl506"}; 
            break;
            case 6: subjects = {"ecl601", "ecl602", "ecl603", "ecl604", "ecl605", "ecl606"}; 
            break;
            case 7: subjects = {"ecl701", "ecl702", "ecl703", "ecl704", "ecl705", "ecl706"}; 
            break;
            case 8: subjects = {"ecl801", "ecl802", "ecl803", "ecl804", "ecl805", "ecl806"}; 
            break;
            default: cout << "Invalid semester for ECE\n"; 
            return;
        }
    } else if (branch == "eci") {
        switch (sem) {
            case 1: subjects = {"eil101", "eil102", "eil103", "eil104", "eil105", "eil106"}; 
            break;
            case 2: subjects = {"eil201", "eil202", "eil203", "eil204", "eil205", "eil206"}; 
            break;
            case 3: subjects = {"eil301", "eil302", "eil303", "eil304", "eil305", "eil306"}; 
            break;
            case 4: subjects = {"eil401", "eil402", "eil403", "eil404", "eil405", "eil406"}; 
            break;
            case 5: subjects = {"eil501", "eil502", "eil503", "eil504", "eil505", "eil506"}; 
            break;
            case 6: subjects = {"eil601", "eil602", "eil603", "eil604", "eil605", "eil606"}; 
            break;
            case 7: subjects = {"eil701", "eil702", "eil703", "eil704", "eil705", "eil706"}; 
            break;
            case 8: subjects = {"eil801", "eil802", "eil803", "eil804", "eil805", "eil806"}; 
            break;
            default: cout << "Invalid semester for ECI\n"; 
            return;
        }
    } else if (branch == "csd") {
        switch (sem) {
            case 1: subjects = {"cdl101", "cdl102", "cdl103", "cdl104", "cdl105", "cdl106"}; 
            break;
            case 2: subjects = {"cdl201", "cdl202", "cdl203", "cdl204", "cdl205", "cdl206"}; 
            break;
            case 3: subjects = {"cdl301", "cdl302", "cdl303", "cdl304", "cdl305", "cdl306"}; 
            break;
            case 4: subjects = {"cdl401", "cdl402", "cdl403", "cdl404", "cdl405", "cdl406"}; 
            break;
            case 5: subjects = {"cdl501", "cdl502", "cdl503", "cdl504", "cdl505", "cdl506"}; 
            break;
            case 6: subjects = {"cdl601", "cdl602", "cdl603", "cdl604", "cdl605", "cdl606"}; 
            break;
            case 7: subjects = {"cdl701", "cdl702", "cdl703", "cdl704", "cdl705", "cdl706"}; 
            break;
            case 8: subjects = {"cdl801", "cdl802", "cdl803", "cdl804", "cdl805", "cdl806"}; 
            break;
            default: cout << "Invalid semester for CSD\n"; 
            return;
        }
    } else if (branch == "csh") {
        switch (sem) {
            case 1: subjects = {"chl101", "chl102", "chl103", "chl104", "chl105", "chl106"}; 
            break;
            case 2: subjects = {"chl201", "chl202", "chl203", "chl204", "chl205", "chl206"}; 
            break;
            case 3: subjects = {"chl301", "chl302", "chl303", "chl304", "chl305", "chl306"}; 
            break;
            case 4: subjects = {"chl401", "chl402", "chl403", "chl404", "chl405", "chl406"}; 
            break;
            case 5: subjects = {"chl501", "chl502", "chl503", "chl504", "chl505", "chl506"}; 
            break;
            case 6: subjects = {"chl601", "chl602", "chl603", "chl604", "chl605", "chl606"}; 
            break;
            case 7: subjects = {"chl701", "chl702", "chl703", "chl704", "chl705", "chl706"}; 
            break;
            case 8: subjects = {"chl801", "chl802", "chl803", "chl804", "chl805", "chl806"}; 
            break;
            default: cout << "Invalid semester for CSH\n"; 
            return;
        }
    } else {
        cout << "Invalid branch entered.\n";
        return;
    }
    for (int i = 0; i < subjects.size(); ++i) {
        cout << i + 1 << " -> " << subjects[i] << "\n";
    }

    cout << "Enter your subjects by selecting the code numbers:\n";
    for (int i = 0; i < 6; ++i) {
        int sub_index;
        cout << "Enter subject index: ";
        cin >> sub_index;
        if (sub_index > 0 && sub_index <= subjects.size()) {
            outfile << subjects[sub_index - 1] << " ";
        } else {
            cout << "Invalid subject selection, please select a valid subject.\n";
            --i;
        }
    }

    cout << "Data saved successfully to " << branch << "_students.txt\n";
    time_t now = time(0);
    char* dt = ctime(&now);
    outfile << "      " << dt;
    outfile.close();
    
}  
};

int registration::paskey;
 
void new_sem_registeration(){

	registration reg;
    reg.load_login_data();
    reg.login();
}

/////////////////////// registration ends //////////////////////////////////////////////



//////------------------feedback starts----------------//////////////////////////

class Feedback {
private:
    struct TeacherFeedback {
        string teacherName;
        int knowledge;
        int communication;
        int punctuality;
    };

    TeacherFeedback teachers[5];

public:
    // Constructor to initialize predefined teacher names
    Feedback() {
        teachers[0].teacherName = "Dr. Milind Penurkar";
        teachers[1].teacherName = "Dr. Mayuri Digalwar";
        teachers[2].teacherName = "Dr. Richa Makhijani";
        teachers[3].teacherName = "Dr. Pradeep Shende";
        teachers[4].teacherName = "Dr. Devyani Gupta";
    }

    // Method to collect feedback for each teacher
    void collectFeedback() {
        for (int i = 0; i < 5; i++) {
            cout << "\nEnter feedback for " << teachers[i].teacherName << ":\n";
            cout << "Rate Knowledge (1-5): ";
            cin >> teachers[i].knowledge;
            cout << "Rate Communication Skills (1-5): ";
            cin >> teachers[i].communication;
            cout << "Rate Punctuality (1-5): ";
            cin >> teachers[i].punctuality;
        }
    }

    // Method to calculate and save the average rating for each teacher
    void saveAverageFeedback(const Student &student) const {
        ofstream avgFile("teacher_average_feedback.txt", ios::app); // Open in append mode
        if (avgFile.is_open()) {
            avgFile << "Student Name: " << student.getName() << "\n";
            for (int i = 0; i < 5; i++) {
                float averageRating = (teachers[i].knowledge + teachers[i].communication + teachers[i].punctuality) / 3.0;
                avgFile << "Teacher: " << teachers[i].teacherName << "\n";
                avgFile << "Average Rating: " << averageRating << "\n";
                avgFile << "---------------------------------------\n";
            }
            avgFile.close();
            cout << "Average feedback saved successfully!" << endl;
        } else {
            cout << "Unable to open file for writing average feedback." << endl;
        }
    }

    // Method to save individual feedback to a file
    void saveFeedback(const Student &student) const {
        ofstream file("feedback.txt", ios::app); // Open in append mode
        if (file.is_open()) {
            file << "Student Name: " << student.getName() << "\n"; // Only student name is saved
            for (int i = 0; i < 5; i++) {
                file << "\nTeacher: " << teachers[i].teacherName << "\n";
                file << "Knowledge: " << teachers[i].knowledge << "\n";
                file << "Communication Skills: " << teachers[i].communication << "\n";
                file << "Punctuality: " << teachers[i].punctuality << "\n";
                file << "---------------------------------------\n";
            }
            file.close();
            cout << "Feedback saved successfully!" << endl;

            // Save average feedback as well
            saveAverageFeedback(student);
        } else {
            cout << "Unable to open file for writing feedback." << endl;
        }
    }
};

// FeePayment Class and main function remain unchanged.

// FeePayment Class
class FeePayment {
private:
    float amountPaid;
    string paymentDate;
    int semester;

public:
    // Constructor to initialize payment details
    FeePayment(float amountPaid, string paymentDate, int semester) {
        this->amountPaid = amountPaid;
        this->paymentDate = paymentDate;
        this->semester = semester;
    }

    // Method to save payment details to a file
    void savePayment(const Student &student) const {
        ofstream file("fee.txt", ios::app); // Open in append mode
        if (file.is_open()) {
            file << "Student BT ID: " << student.getBtID() << "\n";
            file << "Student Name: " << student.getName() << "\n";
            file << "Semester: " << semester << "\n";
            file << "Amount Paid: " << amountPaid << " INR\n";
            file << "Payment Date: " << paymentDate << "\n";
            file << "---------------------------------------\n";
            file.close();
            cout << "Payment recorded successfully!" << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }
};


void studentFeedback(){
	string btID, name;
    int choice;

    cout << "Enter your BT ID: ";
    getline(cin, btID);
    cout << "Enter your name: ";
    getline(cin, name);

    // Create a Student object
    Student student(btID, name);

	Feedback feedback;
    feedback.collectFeedback();
    feedback.saveFeedback(student);
}

void feePayment(){
	string btID, name;
    int choice;

    cout << "Enter your BT ID: "<<endl;
    getline(cin, btID);
    cout << "Enter your name: "<<endl;
    getline(cin, name);

    // Create a Student object
    Student student(btID, name);

   
        string paymentDate;
        float amountPaid;
        int semester;

        cout << "Enter semester (e.g. 1-8): ";
        cin>>semester;
        if( semester%2 == 0)
        {
            do{
            cout << "Amount for payment(123850 .INR): ";
            cin >> amountPaid;
            if(amountPaid != 123850)
             cout<<"Your payment is not acceptable!\n";
            }while(amountPaid != 123850);
        }else{
            do{
                cout << "Amount for payment(123150 .INR): ";
                cin >> amountPaid;
                if(amountPaid != 123150)
                    cout<<"Your payment is not acceptable!\n";
            }while(amountPaid != 123150);

        }

        cin.ignore(); // To ignore newline character after amount input
        cout << "Enter payment date (DD-MM-YYYY): ";
        getline(cin, paymentDate);

        // Create a FeePayment object and save payment
        FeePayment feePayment(amountPaid, paymentDate, semester);
        feePayment.savePayment(student);
    // } else {
    //     cout << "Invalid choice! Please run the program again and choose a valid option." << endl;
    // }
}

//////////////////////// attenndance starts ///////////////////////////////////
class AttendanceTracker {
private:
    map<string, vector<string>> students;            // Map for year-branch to roll numbers
    map<string, map<string, pair<int, int>>> stats;  // Map for attendance stats: {roll_no -> {present_count, total_count}}

    void loadStudents(const string &filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }

        string roll_no;
        while (file >> roll_no) {
            string year = roll_no.substr(2, 2);        // Extract admission year
            string branch = roll_no.substr(4, 3);     // Extract branch
            string key = year + "-" + branch;          // Combine year and branch as key
            students[key].push_back(roll_no);

            // Initialize attendance stats for each student (0 present, 0 total)
            stats[key][roll_no] = {0, 0}; // {present_count, total_count}
        }
        file.close();
    }

    void loadAttendanceData() {
        ifstream file("attendance_data.txt");
        if (!file) {
            cout << "No previous attendance data found. Starting fresh.\n";
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string year, branch, roll_no, status;
            int present_count, total_count;

            ss >> year >> branch >> roll_no >> present_count >> total_count;

            string key = year + "-" + branch;
            stats[key][roll_no] = {present_count, total_count};
        }

        file.close();
    }

    void saveAttendanceData() const {
        ofstream file("attendance_data.txt");
        if (!file) {
            cerr << "Error: Unable to open attendance data file.\n";
            return;
        }

        for (const auto &year_branch : stats) {
            for (const auto &student : year_branch.second) {
                const string &roll_no = student.first;
                int present_count = student.second.first;
                int total_count = student.second.second;
                file << year_branch.first.substr(0, 2) << " "  // Extract year
                     << year_branch.first.substr(3) << " "    // Extract branch
                     << roll_no << " "
                     << present_count << " "
                     << total_count << "\n";
            }
        }

        file.close();
    }

    void saveAttendanceReport() const {
        ofstream report("attendance_report.txt");
        if (!report) {
            cerr << "Error: Unable to create attendance report file." << endl;
            return;
        }

        report << "Roll No\t\tAttendance Percentage\n";
        report << "---------------------------------\n";

        for (const auto &year_branch : stats) {
            for (const auto &student : year_branch.second) {
                const string &roll_no = student.first;
                int present_count = student.second.first;
                int total_count = student.second.second;

                double percentage = total_count > 0 ? (present_count * 100.0 / total_count) : 0.0;
                report << roll_no << "\t\t" << percentage << "%\n";
            }
        }

        report.close();
        cout << "Attendance report saved to 'attendance_report.txt'.\n";
    }

public:
    AttendanceTracker(const string &filename) {
        loadStudents(filename);
        loadAttendanceData();
    }

    void recordAttendance() {
        string year, branch;
        cout << "Enter admission year (e.g., 21, 22, 23): ";
        cin >> year;
        cout << "Enter branch (e.g., CSE, CSD, CSH): ";
        cin >> branch;

        // Convert branch to uppercase to match key format
        transform(branch.begin(), branch.end(), branch.begin(), ::toupper);

        // Construct key
        string key = year + "-" + branch;
        auto it = students.find(key);
        if (it == students.end() || it->second.empty()) {
            cout << "No students found for year " << year << " and branch " << branch << ".\n";
            return;
        }

        cout << "Recording attendance for year " << year << " and branch " << branch << ":\n";
        for (const auto &roll_no : it->second) {
            string status;
            cout << roll_no << " (P for Present / A for Absent): ";
            cin >> status;

            // Increment total count for the student
            stats[key][roll_no].second++;

            // Validate input: Only 'P' or 'A' is accepted
            if (status == "P" || status == "p") {
                stats[key][roll_no].first++; // Increment present count
            } else if (status != "A" && status != "a") {
                cout << "Invalid input. Defaulting to Absent.\n";
            }
        }
        cout << "Attendance recorded successfully.\n";

        // Save updated attendance data
        saveAttendanceData();

        // Save attendance report after recording
        saveAttendanceReport();
    }

    void showAttendance() const {
        string year, branch;
        cout << "Enter admission year (e.g., 21, 22, 23): ";
        cin >> year;
        cout << "Enter branch (e.g., CSE, CSD, CSH): ";
        cin >> branch;

        // Convert branch to uppercase to match key format
        transform(branch.begin(), branch.end(), branch.begin(), ::toupper);

        string key = year + "-" + branch;
        auto it = stats.find(key);
        if (it != stats.end()) {
            cout << "\nAttendance for year " << year << " and branch " << branch << ":\n";
            cout << "Roll No\t\tAttendance Percentage\n";
            cout << "---------------------------------\n";
            for (const auto &student : it->second) {
                const string &roll_no = student.first;
                int present_count = student.second.first;
                int total_count = student.second.second;

                double percentage = total_count > 0 ? (present_count * 100.0 / total_count) : 0.0;
                cout << roll_no << "\t\t" << percentage << "%\n";
            }
        } else {
            cout << "No attendance recorded for year " << year << " and branch " << branch << ".\n";
        }
    }
};
/////////////////////////////// attendance trecking /////////////////////////////////

void attendanceTrecking(){
    AttendanceTracker tracker("login_data.txt");
    int choice;

    do {
        cout << "\n--- Attendance Management System ---\n";
        cout << "1. Record Attendance\n";
        cout << "2. Show Attendance\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tracker.recordAttendance();
                break;
            case 2:
                tracker.showAttendance();
                break;
            case 3:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

}

class admin : public registration{
    public:
    // Method to load login data from file
    void load_login_data(char check) {
        string id;
        int pass;
        if(check == '1'){
            ifstream infile("admin.txt");
            while (infile >> id >> pass) {
            st_login[id] = pass; // Load each ID-password pair into the map
            }
        infile.close();
        }
        
        else if(check == '2'){
            ifstream infile("login_fac.txt");
            while (infile >> id >> pass) {
            st_login[id] = pass; // Load each ID-password pair into the map
            }
        infile.close();
        }

        else if(check == '3'){
            ifstream infile("login_data.txt");
            while (infile >> id >> pass) {
            st_login[id] = pass; // Load each ID-password pair into the map
            }
        infile.close();
        }
    }

    // Method to handle user login
    bool login(char check2) {
        cout << "Enter your BT id: ";
        cin >> btid;
        cout << "Enter your password: ";
        cin >> paskey;
        
        // Check if BT id and password match
        if (st_login.find(btid) != st_login.end() && st_login[btid] == paskey) {
            cout << "Welcome, you are successfully logged in.\n";
            if(check2 == '1')
            displayAdminMenu();  // Call admin menu on successful login
            else if(check2 == '2')
            displayFacultyMenu();
            else if(check2 == '3')
            displayStudentMenu();


            return true;
        } else {
            cout << "Invalid ID or password, please try again.\n";
            char p;
            cout << "To go back press 1, otherwise press any other key: ";
            cin >> p;
            if (p == '1') {
                return false;  // Return to main menu
            } else {
                login(check2);  // Try logging in again
            }
        }
        return false;
    }

    // Admin menu to perform tasks after login
    void displayAdminMenu() {
        int ch2;
        do {
            cout << "\n\t\t\tSTUDENT INFORMATION SECTION\n";
            cout << "\t\t\t     ADMISSION DETAILS\n";
            cout << "\t1. Register Student\n";
            cout << "\t2. Display all Records\n";
            cout << "\t3. Search for a Record\n";
            cout << "\t4. Delete a Record\n";
            cout << "\t0. Exit to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> ch2;

            if(ch2==1)
            {
                insertStudent();
            }
            else if (ch2 == 2)
            {
                cout<<"displain\n";
                 dispStudentRecord();
            }
            else if (ch2 == 3)
            {
                // cout<<"searching\n";
                searchByRollNo();
            }
            else if (ch2 == 4)
            {
                // cout<<"deletng\n";
                delStudentRecord();
            }
            else if (ch2 ==0)
            {
                cout<<"exitting\n";
                return;
            }
            else 
            {
                cout<<"enter a valid choice\n";
            }

            
        } while (ch2 != 0);
    }

    void displayFacultyMenu(){
        
        fflush(stdin);
					load();
					do
					{
						CLS();
						RULE("*");
						cout << "\t\t\tFACULTY INFORMATION SECTION";
						RULE("*");
						cout << "\t\t\t    	GRADING SYSTEM";
						RULE('-');

						cout << "\t1.  Upload Grades\n";
						cout << "\t2.  View All Grades\n";
						cout << "\t3.  Search Grades By Roll Number\n";
                        cout << "\t4.  Attendance Tracking\n";
                        cout << "\t5.  Club Section\n";
						cout << "\t0.  Exit.\n";
						cout << "\nEnter your choice : ";

						cin >> w;
						switch (w)
						{
						case 1:
							insertGrade();
							break;
						case 2:
							dispGrade();
							break;
						case 3:
							searchGradeByRollNo();
							break;
                        case 4:
                            attendanceTrecking();
							break;    
                        case 5:
                            clubSection();
							break;      
						}
						fflush(stdin);
						if (w)
							cin >> ch;
						else
							load();
					} while (w != 0);
    }

    void displayStudentMenu(){

        fflush(stdin);
					load();
					do
					{
						CLS();
						RULE("*");
						cout << "\t\t\tSTUDENT INFORMATION SECTION";
						RULE("*");
						cout << "\t\t\t    	GRADING SYSTEM";
						RULE('-');

						// cout << "\t1.  Upload Grades\n";
						// cout << "\t1.  View All Grades\n";
                        cout << "\t1.  Registration for the new semester\n";
						cout << "\t2.  Search Your Grades By Roll Number\n";
                        cout << "\t3.  Student_Feedback\n";
                        cout << "\t4.  Academic Fee Payment\n";
						cout << "\t0.  Exit.\n";
						cout << "\nEnter your choice : ";

						cin >> w;
						switch (w)
						{
						case 1:
							new_sem_registeration();
							break;
						case 2:
							searchGradeByRollNo();
							break;
						case 3:
							studentFeedback();
							break;
                        case 4:
                            feePayment();
                            break;
						}
                        
						fflush(stdin);
						if (w)
							cin >> ch;
						else
							load();
					} while (w != 0);
    }
    
 
};

int main()
{
	int a = 1, w;
	ifstream file1;
	ofstream file2;
	Grade g1;
	char ch5;
	char ch;
	char ch1;
	int ch2;
	//	load();

	do {
		CLS();
		RULE("*");
		cout << "\t\t\tCOLLEGE MANAGEMENT SYSTEM";
		RULE("*");
		cout << "\t1. LOGIN AS AN ADMIN\n";
        cout << "\t2. LOGIN AS A FACULTY\n";
        cout << "\t3. LOGIN AS A STUDENT\n";
		cout << "\t0. Exit.\n\n";
		cout << "Enter your choice : ";
		fflush(stdin);
		cin >> ch5;

        if(ch5 == '1'){
            admin a;
            a.load_login_data('1');
            if(a.login('1')){
                cout << "Welcome as an Admin\n";
            }
        }
        if(ch5 == '2'){
            admin a;
            a.load_login_data('2');
            if(a.login('2')){
                cout << "Welcome as a Faculty\n";
            }
        }
        if(ch5 == '3'){
            admin a;
            a.load_login_data('3');
            if(a.login('3')){
                cout << "Welcome as a Student\n";
            }
        }
	
	} while (ch5 != '0');
}