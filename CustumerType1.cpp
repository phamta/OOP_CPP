#include "CustumerType1.h"
#include <string>

std::string CustumerType1::NameCustumerType1 = "Khach hang tap theo ngay";
int CustumerType1::Count1 = 1;

void CustumerType1::ReadFile(std::ifstream& ifs) {
    std::string line;
    if (std::getline(ifs, line)) {
        std::istringstream iss(line);
        getline(iss, FullName, ',');
        getline(iss, BornYear, ',');
        ifs.ignore(1, ',');
        getline(iss, Gender, ',');
        ifs.ignore(1, ',');
        getline(iss, PhoneNumber, ',');
        ifs.ignore(1, ',');

        std::string s;
        History.clear();

        while (getline(iss, s, ',')) {
            if (s.find('-') != std::string::npos) {
                s.erase(s.find('-'));
                History.push_back(s);
                break;
            }
            History.push_back(s);
        }
    }
}


void CustumerType1::WriteFile(const std::string& filename){
    std::ofstream ofs(filename,std::ios::app);
    if(!ofs) {
        std::cerr<<"Can't open output file.\n";
        return;
    }

    if(Count1 == 1){
        Count1 = 0;
    }
    else{
        ofs << std::endl << "   ";
    }

ofs << FullName << "," << BornYear << "," << Gender << "," << PhoneNumber;
for(int i = 0; i < History.size(); ++i) {
    ofs << "," << History[i];
}
ofs << "-";

ofs.close();
}


void CustumerType1::Show(){
    std::cout << "----------------------------------------------" << std::endl;
    Human::Show();
    std::cout << "|" << std::setw(17) << "Nhung ngay tap : " << this->History[0] << std::setw(18) << "|" << std::endl;
    for(int i=1; i<this->History.size(); ++i){
        std::cout << "|" << std::setw(27) << this->History[i] << std::setw(18) << "|" << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
    
}

void CustumerType1::Update(){
    int temp = 1;
    int input;
    int choice = 1;
    int MaxChoice = 5;
    do{
        system("cls");
        std::cout<<"Chon dich vu muon cap nhat:"<<std::endl;
            std::cout << (choice == 1 ? ">":" ") << "Ten khach hang hien tai: " << this->GetName() << std::endl;
            std::cout << (choice == 2 ? ">":" ") << "Nam sinh khach hang hien tai: " << this->GetYear() << std::endl;
            std::cout << (choice == 3 ? ">":" ") << "Gioi tinh khach hang hien tai: " << this->GetGender() << std::endl;
            std::cout << (choice == 4 ? ">":" ") << "So dien thoai khach hang hien tai: " << this->GetPhoneNumber() << std::endl;
            std::cout << (choice == 5 ? ">":" ") << "Thoat" << std::endl;

            input = getch();

            if (input == 80) { // Mũi tên đi xuống (lên)
            if (choice == MaxChoice) {
                choice = 1; // Di chuyển lên đầu danh sách
            } else {
                choice++;
            }
        } else if (input == 72) { // Mũi tên lên (xuống)
            if (choice == 1) {
                choice = MaxChoice; // Di chuyển xuống cuối danh sách
            } else {
                choice--;
            }
        }

        if(input == 13){
            switch (choice){
                case 1:
                    if(temp == 1){
                        std::cin.ignore();
                        temp = 0;
                    } 
                    std::cout << "Cap nhat ten : " << std::endl;
                    getline(std::cin,this->FullName);
                    break;
                case 2:
                    temp = 1;
                    std::cout << "Cap nhat nam sinh : ";
                    std::cin >> this->BornYear;
                    std::cout << "Da cap nhat lai nam sinh cua khach hang" << std::endl;
                    break;

                case 3:
                    temp = 1;
                    std::cout << "Cap nhat lai gioi tinh : ";
                    this->Gender = Human::ChooseGender();
                    std::cout << "Da cap nhat lai gioi tinh cua khach hang " << std::endl;
                    break;
                case 4:
                    temp = 1;
                    std::cout << "Nhap so dien thoai moi : ";
                    std::cin >> this->PhoneNumber;
                    std::cout << "Da cap nhat lai so dien thoai cua khach hang" << std::endl;
                    break;
                case 5:
                    std::cout << "Da thoat khoi muc chinh sua thong tin" << std::endl;
                    return;
                    break;
            }
        }
    }while (input != '0');
}

std::string CustumerType1::InputTrainDay(){
    // p1.SetTime();
    std::string day = p1.DayNow;
    std::string month = (p1.MonthNow);
    std::string year1 = (p1.YearNow);

    std::string date1 = day + "/" + month + "/" + year1;
    std::string date2;
    int year = p1.StringToInt(p1.YearNow);
    int high;

    int input;
    int choice = 1;
    int maxChoice = 5;

    bool check = true;

    do
    {
        system("cls");
        std::cout  <<"Them ngay thang dang ky" << std::endl;
        std::cout << "Ngay dang chon " << day << "/" << month << "/" << year1 << std::endl;
        // std::cout << this->History.back() << std::endl;
        std::cout << (choice == 1 ? ">":" ") <<"Chon ngay tap " << std::endl;
        std::cout << (choice == 2 ? ">":" ") <<"Chon thang tap " << std::endl;
        std::cout << (choice == 3 ? ">":" ") <<"Chon nam tap" << std::endl;
        std::cout << (choice == 4 ? ">":" ") <<"Hoan thanh" << std::endl;
        std::cout << (choice == 5 ? ">":" ") <<"Thoat" << std::endl;

        input = getch();

        if (input == 80) { // Mũi tên đi xuống (lên)
            if (choice == maxChoice) {
                choice = 1; // Di chuyển lên đầu danh sách
            } else {
                choice++;
            }
        } else if (input == 72) { // Mũi tên lên (xuống)
            if (choice == 1) {
                choice = maxChoice; // Di chuyển xuống cuối danh sách
            } else {
                choice--;
            }
        }

        if (input == 13)
        {
            switch (choice)
            {
                case 2:
                    do
                    {
                        month = p1.ChooseMonth();
                        date2 = day + "/" + month + "/" + year1;
                        if (p1.CompareDay(date2,date1))
                        {
                            std::cout << "Thang vua chon khong hop le " << std::endl;
                            continue;
                        }
                        // temp1 = 1;
                        break;
                    } while (1);
                    break;

                case 1:
                    if(month == "2"){
                        (year%4 == 0 && year%100 != 0) ? high = 29 : high = 28; 
                    }
                    else if (month == "4" || month == "6" || month == "9" || month == "11")
                    {
                        high = 30;
                    }
                    else{
                        high = 31;
                    }

                    do
                    {
                        day = p1.ChooseDay(high,check);
                        date2 = day + "/" + month + "/" + year1;
                        if (p1.CompareDay(date2,date1))
                        {
                            check = false;
                            continue;
                        }
                        break;
                    } while (1);
                    break;

                case 4:
                    std::cout << "Hoan thanh viec nhap ngay thang tap" << std::endl;
                    return day + "/" + month + "/"+ year1;    
                    input = '0';
                    system("pause");
                    // return;
                case 3:
                    do
                    {
                        year1 = p1.ChooseYear(true);
                        date2 = day + "/" + month + "/" + year1;
                        if (p1.CompareDay(date2,date1))
                        {
                            check = false;
                            continue;
                        }
                        break;
                    } while (1);
                    
                    break;
                case 5:
                    std::cout << "Da thoat khoi muc nhap ngay thang tap" << std::endl;
                    return "0";
                    break;
            }
        }
        
    } while (input != '0');

    // return day + "/" + month;    
}

void CustumerType1::AddTrainDay(){
    std::string s = InputTrainDay();
    if (s == "0")
    {
        return;
    }
    
    if(s[2] != '/') s = "0" + s;
    if(s[5] != '/') s.insert(3,"0");
    std::cout << this->History.size() << std::endl;
    this->History.push_back(s);    
}

int CustumerType1::Input(const std::string& s){
    if(!Human::Nhap(s)) return 0;
    // std::cout << "1" << std::endl;
    this->History.clear();
    this->AddTrainDay();
    return 1;
}

//test thu
