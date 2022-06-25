#include <bits/stdc++.h>
using namespace std;

class student
{
    int id;
    string name;
    int cls;
    int subjectCount = 0;
    int daysTaught = 0;
    int earnings = 0;
    double totalMarks = 0;
    bool subjectTeach[3]={0};   
public:
    
    void setId(int s_id)
    {
        id =s_id;
    }
    void setName(string s_name)
    {
        name =s_name;
    }
    void setCls(int s_cls)
    {
        cls =s_cls;
    }
    void setDaysTaught(int s_totalDaysTaught)
    {
        daysTaught = s_totalDaysTaught;
    }
    void setEarnings(int s_totalEarnings)
    {
        earnings = s_totalEarnings;
    }
    void setTotalMarks(double s_totalMarks)
    {
        totalMarks = s_totalMarks;
    }
    void setSubjectCount(int count)
    {
        subjectCount = count;
    }
    void setSubjectTeach(bool s_subjectTeach[])
    {
        for(int i=0;i<3;i++)
          {
            subjectTeach[i]=s_subjectTeach[i];
          }
    }
    int getcount()
    {
        return subjectCount;
    }
    int getId()
    {
        return id;
    }
    int getCls()
    {
        return cls;
    }
    string getName()
    {
        return name;
    }
    bool* getSubjects()
    {
        return subjectTeach;
    }
    double getTotalMarks()
    {
        return totalMarks;
    }
    int getDaysTaught()
    {
        return daysTaught;
    }
    int getEarnings()
    {
        return earnings;
    }

    void setTotalAvgMark();
    double editNewMark(bool subjects[],int sub_count);
    void addDays(int days);
    void addMarks(int marks)
    {
        totalMarks = totalMarks + marks;
    }

};

class cls_eight : public student
{
public:
   void student_detail_cls_eight(int id_,string name_,double totalMarks_,int daysTaught_,int earnings_)
   {
       cout<<"Id: "<<id_<<"   Name: "<<name_<<"   Avg. Marks: "<<totalMarks_<<"   Total Days Taught: "<<daysTaught_<<"   Total Earnings: "<<earnings_<<endl;
   }
};

class cls_nine : public student
{
public:
   void student_detail_cls_nine(int id_,string name_,double totalMarks_,int daysTaught_,int earnings_)
   {
       cout<<"Id: "<<id_<<"   Name: "<<name_<<"   Avg. Marks: "<<totalMarks_<<"   Total Days Taught: "<<daysTaught_<<"   Total Earnings: "<<earnings_<<endl;
   }
};

class cls_ten : public student
{
public:
   void student_detail_cls_ten(int id_,string name_,double totalMarks_,int daysTaught_,int earnings_)
   {
       cout<<"Id: "<<id_<<"   Name: "<<name_<<"   Avg. Marks: "<<totalMarks_<<"   Total Days Taught: "<<daysTaught_<<"   Total Earnings: "<<earnings_<<endl;
   }
};

void student :: setTotalAvgMark()
{
    cout<<"Enter marks of student: "<<endl;
    int mathematics=0,english=0,bangla=0;

    if(subjectTeach[0]==1)
    {
        cout<<"Mathematics Score: "; cin>>mathematics;
    }
    if(subjectTeach[1]==1)
    {
        cout<<"English Score: "; cin>>english;
    }
    if(subjectTeach[2]==1)
    {
        cout<<"Bangla Score: "; cin>>bangla;
    }
       
    totalMarks = (double) ((bangla+english+mathematics)/subjectCount);
}

double student :: editNewMark(bool subjects[],int sub_count)
{
    cout<<"Enter new marks of the student:( values must range from (0 to 100) )"<<endl;
    int mathematics=0,bangla=0,english=0;
    if(subjects[0]==1)
    {
        cout<<"mathematics new marks: "; cin>>mathematics;
    }
    if(subjects[1]==1)
    {
        cout<<"English new marks: "; cin>>english;
    }
    if(subjects[2]==1)
    {
        cout<<"Bangla new marks: "; cin>>bangla;
    }
    double edit_marks;
    edit_marks=(double) ((mathematics+english+bangla)/sub_count);

    return edit_marks;
}
void student :: addDays(int days)
{
    daysTaught = daysTaught + days;
    int extraEarnings = subjectCount * days;
    earnings = earnings + extraEarnings;
}


int main()
{
    int option;
    int clas;
    cls_eight clsEightObject[100];
    cls_nine clsNineObject[100];
    cls_ten clsTenObject[100];



    cout << "...............Student Tracking..................." << endl;
    cout << "Enter option:" << endl;
    cout<<"Press 1: For adding student"<<endl;
    cout<<"Press 2: For editing student"<<endl;
    cout<<"Press 3: For deleting student"<<endl;
    cout<<"Press 4: For displaying list of students"<<endl;
    cout<<"Press 5: For Overall info of all students"<<endl;
    while (scanf("%d",&option)!=EOF)
    {
        if (option == 1)
        {
            cout << "Which Class: Press 8 for class Eight , Press 9 for class Nine or Press 10 for class 10"<< endl;
            cin >> clas;
            if (clas == 8)
            {
                cout << "Adding Student-----Class Eight" << endl;
                cout << "Enter how many students you want to add: ";
                int num;
                cin >> num;

                if (num > 0)
                {
                  for(int i=0;i<num;i++)
                  {

                    int id, cls = 8, totalDaysTaught, totalEarnings;
                    string name;
                    bool subjectTeach[3] = {0};
                    cout << "Enter Id: "; cin >> id;
                    cout << "Enter name: "; cin >> name;
                    cout << "Enter total days taught: "; cin >> totalDaysTaught;
                    cout << "Enter total earning: "; cin >> totalEarnings;
                    
                    clsEightObject[i].setId(id);
                    clsEightObject[i].setName(name);
                    clsEightObject[i].setCls(cls);
                                 
                    cout << "Enter Subjects you teach:(only boolean values): 1 means teach the subject, 0 means not "<<endl;
                    cout<<"Input Sequence Mathematics, English, Bangla: ";
                    int count = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        bool subject_;
                        cin >> subject_;
                        if (subject_ == true)
                        {
                            subjectTeach[j] = 1;
                            count++;
                        }
                    }

                    clsEightObject[i].setSubjectTeach(subjectTeach);
                    clsEightObject[i].setSubjectCount(count);
                    clsEightObject[i].setTotalAvgMark();
                    clsEightObject[i].setDaysTaught(totalDaysTaught);
                    clsEightObject[i].setEarnings(totalEarnings);
                    cout<<endl;
                  }
                }
                if(num<=0)
                {
                    cout<<"Invalid number pressed: "<<endl;
                }
            }

            if (clas == 9)
            {
                cout << "Adding Student-----Class Nine" << endl;
                cout << "Enter how many students you want to add: ";
                int num;
                cin >> num;

                if (num > 0)
                {
                  for(int i=0;i<num;i++)
                  {

                    int id, cls = 8, totalDaysTaught, totalEarnings;
                    string name;
                    bool subjectTeach[3] = {0};
                    cout << "Enter Id: "; cin >> id;
                    cout << "Enter name: "; cin >> name;
                    cout << "Enter total days taught: "; cin >> totalDaysTaught;
                    cout << "Enter total earning: "; cin >> totalEarnings;
                    
                    clsNineObject[i].setId(id);
                    clsNineObject[i].setName(name);
                    clsNineObject[i].setCls(cls);
                                 
                    cout << "Enter Subjects you teach:(only boolean values): 1 means teach the subject, 0 means not "<<endl;
                    cout<<"Input Sequence Mathematics, English, Bangla: ";
                    int count = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        bool subject_;
                        cin >> subject_;
                        if (subject_ == true)
                        {
                            subjectTeach[j] = 1;
                            count++;
                        }
                    }

                    clsNineObject[i].setSubjectTeach(subjectTeach);
                    clsNineObject[i].setSubjectCount(count);
                    clsNineObject[i].setTotalAvgMark();
                    clsNineObject[i].setDaysTaught(totalDaysTaught);
                    clsNineObject[i].setEarnings(totalEarnings);
                    cout<<endl;
                  }
                }
                if(num<=0)
                {
                    cout<<"Invalid number pressed: "<<endl;
                }
            }

            if (clas == 10)
            {
                cout << "Adding Student-----Class Ten" << endl;
                cout << "Enter how many students you want to add: ";
                int num;
                cin >> num;

                if (num > 0)
                {
                  for(int i=0;i<num;i++)
                  {

                    int id, cls = 8, totalDaysTaught, totalEarnings;
                    string name;
                    bool subjectTeach[3] = {0};
                    cout << "Enter Id: "; cin >> id;
                    cout << "Enter name: "; cin >> name;
                    cout << "Enter total days taught: "; cin >> totalDaysTaught;
                    cout << "Enter total earning: "; cin >> totalEarnings;
                    
                    clsTenObject[i].setId(id);
                    clsTenObject[i].setName(name);
                    clsTenObject[i].setCls(cls);
                                 
                    cout << "Enter Subjects you teach:(only boolean values): 1 means teach the subject, 0 means not "<<endl;
                    cout<<"Input Sequence Mathematics, English, Bangla: ";
                    int count = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        bool subject_;
                        cin >> subject_;
                        if (subject_ == true)
                        {
                            subjectTeach[j] = 1;
                            count++;
                        }
                    }

                    clsTenObject[i].setSubjectTeach(subjectTeach);
                    clsTenObject[i].setSubjectCount(count);
                    clsTenObject[i].setTotalAvgMark();
                    clsTenObject[i].setDaysTaught(totalDaysTaught);
                    clsTenObject[i].setEarnings(totalEarnings);
                    cout<<endl;
                  }
                }
                if(num<=0)
                {
                    cout<<"Invalid number pressed: "<<endl;
                }
            }
        }

        if(option == 2)
        {
           cout<<"Which Class: 8 , 9  or 10"<<endl;
           cin>>clas;
           if(clas==8)
           {
               cout<<"Which student you want to edit: Give id:"<<endl;
               int edit_id,edit_day;
               cin>>edit_id;
               edit_id-=1;
               cout<<"Enter new number of days you taught: "<<endl;
               cin>>edit_day;
               clsEightObject[edit_id].addDays(edit_day);
               bool* subjects=clsEightObject->getSubjects();
               int sub_count=clsEightObject[edit_id].getcount();
               double edit_marks=clsEightObject[edit_id].editNewMark(subjects,sub_count);
               clsEightObject[edit_id].addMarks(edit_marks);

           }

           if(clas==9)
           {
               cout<<"Which student you want to edit: Give id:"<<endl;
               int edit_id,edit_day;
               cin>>edit_id;
               edit_id-=1;
               cout<<"Enter new number of days you taught: "<<endl;
               cin>>edit_day;
               clsNineObject[edit_id].addDays(edit_day);
               bool* subjects=clsNineObject->getSubjects();
               int sub_count=clsNineObject[edit_id].getcount();
               double edit_marks=clsNineObject[edit_id].editNewMark(subjects,sub_count);
               clsNineObject[edit_id].addMarks(edit_marks);

           }

           if(clas==10)
           {
               cout<<"Which student you want to edit: Give id:"<<endl;
               int edit_id,edit_day;
               cin>>edit_id;
               edit_id-=1;
               cout<<"Enter new number of days you taught: "<<endl;
               cin>>edit_day;
               clsTenObject[edit_id].addDays(edit_day);
               bool* subjects=clsTenObject->getSubjects();
               int sub_count=clsTenObject[edit_id].getcount();
               double edit_marks=clsTenObject[edit_id].editNewMark(subjects,sub_count);
               clsTenObject[edit_id].addMarks(edit_marks);

           }

        }

        if(option == 3)
        {
            cout<<"Which Class: 8 , 9  or 10"<<endl;
            cin>>clas;
            if(clas==8)
            {
                cout<<"Which Student you want to delete: Give Id"<<endl;
                int st_id,st_num;
                cin>>st_id;
                st_id=st_id-1;
                cout<<"Enter total number of studnet in class eight"<<endl;
                cin>>st_num;
                if(st_num<=0)
                {
                    cout<<"No student to delete"<<endl;
                    break;
                }
                if(st_num>0  && st_id!=st_num-1)
                {
                    for(int i=st_id;i<st_num;i++)
                    {
                       clsEightObject[i]=clsEightObject[i+1];
                    }
                }
                if(st_id==st_num-1)
                {
                    clsEightObject[st_id].setId(0);
                    clsEightObject[st_id].setName("");
                    clsEightObject[st_id].setTotalMarks(0);
                    clsEightObject[st_id].setDaysTaught(0);
                    clsEightObject[st_id].setEarnings(0);
                }
                cout<<"Student Deletetion Succesfull."<<endl;
            }

            if(clas==9)
            {
                cout<<"Which Student you want to delete: Give Id"<<endl;
                int st_id,st_num;
                cin>>st_id;
                st_id=st_id-1;
                cout<<"Enter total number of studnet in class nine"<<endl;
                cin>>st_num;
                if(st_num<=0)
                {
                    cout<<"No student to delete"<<endl;
                    break;
                }
                if(st_num>0  && st_id!=st_num-1)
                {
                    for(int i=st_id;i<st_num;i++)
                    {
                       clsNineObject[i]=clsNineObject[i+1];
                    }

                }
                if(st_id==st_num-1)
                {
                    clsNineObject[st_id].setId(0);
                    clsNineObject[st_id].setName("");
                    clsNineObject[st_id].setTotalMarks(0);
                    clsNineObject[st_id].setDaysTaught(0);
                    clsNineObject[st_id].setEarnings(0);
                }
                cout<<"Student Deletetion Succesfull."<<endl;
            }

            if(clas==10)
            {
                cout<<"Which Student you want to delete: Give Id"<<endl;
                int st_id,st_num;
                cin>>st_id;
                st_id=st_id-1;
                cout<<"Enter total number of studnet in class Ten"<<endl;
                cin>>st_num;
                if(st_num<=0)
                {
                    cout<<"No student to delete"<<endl;
                    break;
                }
                if(st_num>0  && st_id!=st_num-1)
                {
                    for(int i=st_id;i<st_num;i++)
                    {
                       clsTenObject[i]=clsTenObject[i+1];
                    }
                }
                if(st_id==st_num-1)
                {
                    clsTenObject[st_id].setId(0);
                    clsTenObject[st_id].setName("");
                    clsTenObject[st_id].setTotalMarks(0);
                    clsTenObject[st_id].setDaysTaught(0);
                    clsTenObject[st_id].setEarnings(0);
                }
                cout<<"Student Deletetion Succesfull."<<endl;
            }
        }

        if (option== 4)
        {
            cout<<"Which Class: 8,9 or 10"<<endl;
            cin>>clas;
            if(clas==8)
            {
                cout<<"Press 1 for full detail of class, Press 2 for individual student"<<endl;
                int st_detail,st_num_cls_eight;
                cin>>st_detail;
                if( st_detail==1 )
                {
                    cout<<"Enter total student number: ";
                    cin>>st_num_cls_eight;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                    cout<<"                         Student Details Table (Class Eight)                     "<<endl;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                    for(int i=0; i<st_num_cls_eight;i++)
                    {
                        int id_ = clsEightObject[i].getId();
                        string name_ = clsEightObject[i].getName();
                        int totalMarks_ = clsEightObject[i].getTotalMarks();
                        int daysTaught_ = clsEightObject[i].getDaysTaught();
                        int earnings_ = clsEightObject[i].getEarnings();

                        clsEightObject[i].student_detail_cls_eight(id_,name_,totalMarks_,daysTaught_,earnings_);
                    }

                }

                if( st_detail == 2 )
                {
                    int st_id;
                    cout<<"Enter Individual student Id: ";
                    cin>>st_id;
                    st_id=st_id-1;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                    cout<<"                           Student Detail (Class Eight)                          "<<endl;
                    cout<<"---------------------------------------------------------------------------------"<<endl;

                    int id_ = clsEightObject[st_id].getId();
                    string name_ = clsEightObject[st_id].getName();
                    int totalMarks_ = clsEightObject[st_id].getTotalMarks();
                    int daysTaught_ = clsEightObject[st_id].getDaysTaught();
                    int earnings_ = clsEightObject[st_id].getEarnings();

                    clsEightObject[st_id].student_detail_cls_eight(id_,name_,totalMarks_,daysTaught_,earnings_);
                }

            }
            if(clas==9)
            {
                cout<<"Press 1 for full detail of class, Press 2 for individual student"<<endl;
                int st_detail,st_num_cls_nine;
                cin>>st_detail;
                if( st_detail==1 )
                {
                    cout<<"Enter total student number: ";
                    cin>>st_num_cls_nine;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                    cout<<"                      Student Details Table (Class Nine)                         "<<endl;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                    for(int i=0; i<st_num_cls_nine;i++)
                    {
                        int id_ = clsNineObject[i].getId();
                        string name_ = clsNineObject[i].getName();
                        int totalMarks_ = clsNineObject[i].getTotalMarks();
                        int daysTaught_ = clsNineObject[i].getDaysTaught();
                        int earnings_ = clsNineObject[i].getEarnings();

                        clsNineObject[i].student_detail_cls_nine(id_,name_,totalMarks_,daysTaught_,earnings_);
                    }

                }

                if( st_detail == 2 )
                {
                    int st_id;
                    cout<<"Enter Individual student Id: ";
                    cin>>st_id;
                    st_id=st_id-1;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                    cout<<"                        Student Detail (Class Nine)                              "<<endl;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                    int id_ = clsNineObject[st_id].getId();
                    string name_ = clsNineObject[st_id].getName();
                    int totalMarks_ = clsNineObject[st_id].getTotalMarks();
                    int daysTaught_ = clsNineObject[st_id].getDaysTaught();
                    int earnings_ = clsNineObject[st_id].getEarnings();
                    
                    clsNineObject[st_id].student_detail_cls_nine(id_,name_,totalMarks_,daysTaught_,earnings_);

                }

            }

            if(clas==10)
            {
                cout<<"Press 1 for full detail of class, Press 2 for individual student"<<endl;
                int st_detail,st_num_cls_ten;
                cin>>st_detail;
                if( st_detail==1 )
                {
                    cout<<"Enter total student number: ";
                    cin>>st_num_cls_ten;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                    cout<<"                      Student Details Table (Class 10)                           "<<endl;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                    for(int i=0; i<st_num_cls_ten;i++)
                    {
                        int id_ = clsTenObject[i].getId();
                        string name_ = clsTenObject[i].getName();
                        int totalMarks_ = clsTenObject[i].getTotalMarks();
                        int daysTaught_ = clsTenObject[i].getDaysTaught();
                        int earnings_ = clsTenObject[i].getEarnings();
                        
                        clsTenObject[i].student_detail_cls_ten(id_,name_,totalMarks_,daysTaught_,earnings_);
                    }

                }

                if( st_detail == 2 )
                {
                    int st_id;
                    cout<<"Enter Individual student Id: ";
                    cin>>st_id;
                    st_id=st_id-1;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                    cout<<"                         Student Detail (Class 10)                               "<<endl;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                    int id_ = clsTenObject[st_id].getId();
                    string name_ = clsTenObject[st_id].getName();
                    int totalMarks_ = clsTenObject[st_id].getTotalMarks();
                    int daysTaught_ = clsTenObject[st_id].getDaysTaught();
                    int earnings_ = clsTenObject[st_id].getEarnings(); 
                    
                    clsTenObject[st_id].student_detail_cls_ten(id_,name_,totalMarks_,daysTaught_,earnings_);
                }

            }
        }
        if(option==5)
        {
            int num_eight,num_nine,num_ten;
            int days_taught_cls_eight=0, days_taught_cls_nine=0, days_taught_cls_ten=0;
            int cls_eight_earnings=0, cls_nine_earnings=0, cls_ten_earnings=0;
            double avg_mark_cls_eight=0, avg_mark_cls_nine=0, avg_mark_cls_ten=0;
            cout<<"Enter total students of class eight: ";
            cin>>num_eight;
            for(int i=0;i<num_eight;i++)
            {
                days_taught_cls_eight+=clsEightObject[i].getDaysTaught();

            }

            for(int i=0;i<num_eight;i++)
            {
                cls_eight_earnings+=clsEightObject[i].getEarnings();
            }

             for(int i=0;i<num_eight;i++)
            {
                avg_mark_cls_eight+=clsEightObject[i].getTotalMarks();
            }


            cout<<"Enter total students of class nine: ";
            cin>>num_nine;
            for(int i=0;i<num_nine;i++)
            {
                days_taught_cls_nine+=clsNineObject[i].getDaysTaught();

            }

            for(int i=0;i<num_nine;i++)
            {
                cls_nine_earnings+=clsNineObject[i].getEarnings();
            }

            for(int i=0;i<num_nine;i++)
            {
                avg_mark_cls_nine+=clsNineObject[i].getTotalMarks();
            }

            cout<<"Enter total students of class ten: ";
            cin>>num_ten;
            for(int i=0;i<num_ten;i++)
            {
                days_taught_cls_ten+=clsTenObject[i].getDaysTaught();

            }

            for(int i=0;i<num_ten;i++)
            {
                cls_ten_earnings+=clsTenObject[i].getEarnings();
            }

            for(int i=0;i<num_ten;i++)
            {
                avg_mark_cls_ten+=clsTenObject[i].getTotalMarks();
            }

            int total_days_taught_all_cls =0,total_earning_all_cls=0;
            double total_avg_mark_all_cls=0.0;
            int total_students=num_eight+num_nine+num_ten;
            total_days_taught_all_cls= days_taught_cls_eight+ days_taught_cls_nine+days_taught_cls_ten;
            total_earning_all_cls= cls_eight_earnings +cls_nine_earnings+cls_ten_earnings;
            total_avg_mark_all_cls = (avg_mark_cls_eight+avg_mark_cls_nine+avg_mark_cls_ten)/total_students;

            cout<<"---------------------------------------------------------------------------------"<<endl;
            cout<<"                        Overall Student Detail (Class 8,9,10)                    "<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;

            cout<<"Total days taught across all classes: "<<total_days_taught_all_cls<<endl;
            cout<<"Total earning across all classes: "<<total_earning_all_cls<<endl;
            cout<<"Average marks of all students: "<<total_avg_mark_all_cls<<endl;
            cout<<"Total days taught--( for class eight ) : "<<days_taught_cls_eight<<endl;
            cout<<"Total earnings--( for class eight ) : "<<cls_eight_earnings<<endl;
            cout<<"Total days taught--( for class nine ) : "<<days_taught_cls_nine<<endl;
            cout<<"Total earnings--( for class nine ) : "<<cls_nine_earnings<<endl;
            cout<<"Total days taught--( for class Ten ) : "<<days_taught_cls_ten<<endl;
            cout<<"Total earnings--( for class Ten ) : "<<cls_ten_earnings<<endl;

        }

       cout<<"enter option: ";

    }
}
