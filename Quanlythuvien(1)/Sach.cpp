#include"Sach.h"

void InitList(LIST& l) {
	l.head = NULL;
	l.tail = NULL;
}
NODE *getNode(SACH s) {
	NODE* p = new NODE();
	p->data = s;
	p->next = NULL;
	return p;
}
void AddHead(LIST& l, NODE* p) {
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else 
	{
		p->next = l.head;
		l.head = p;
	}
}
void AddTail(LIST& l, NODE* p) {
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
//Đọc file ngày tháng năm
void doc_file_datetime(ifstream &filein,DATETIME &a) {
	filein >> a.ngay;
	filein.seekg(1, 1);
	filein >> a.thang;
	filein.seekg(1, 1);
	filein >> a.nam;
	filein.seekg(1, 1);
}
//Hàm đọc dữ liệu sinh viên từ file
void doc_1_quyen_sach(ifstream& filein, SACH& s) {
	filein >> s.ma;
	filein.seekg(2, 1);
	getline(filein, s.ten,',');//nhap chuoi
	filein.seekg(1, 1);
	getline(filein, s.nxb,',');//nhap chuoi
	filein.seekg(1, 1);
	filein >> s.gia;
	filein.seekg(1, 1);
	filein >> s.nam;
	filein.seekg(1, 1);
	filein >> s.page;
	filein.seekg(1, 1);
	doc_file_datetime(filein,s.ngay);
	filein.seekg(1, 1);
	filein >> s.status;
	string x;
	getline(filein, x);
	
}
bool kiem_tra(SACH& s, NODE* p, LIST& l) {
	for (p = l.head; p != NULL; p = p->next) {
		if (p->data.ma == s.ma) {
			return false;
		}
	}
	return true;
}
void nhap_thong_tin_sach(SACH &s, LIST& l, NODE* p) {//can sua
	//doc_all_sach(filein, l);
	bool b = true;
	while (b) {
	//system("cls");
	cout << "Nhap vao ma sach: ";
	cin >> s.ma;
	bool a=kiem_tra(s, p, l);
	if (a) {
		cin.ignore();
		cout << "Nhap vao ten sach: ";
		getline(cin, s.ten);
		cout << "Nhap vao nha xuat ban: ";
		getline(cin, s.nxb);
		cout << "Nhap vao gia: ";
		cin >> s.gia;
		cout << "Nhap vao nam: ";
		cin >> s.nam;
		cout << "Nhap vao trang sach: ";
		cin >> s.page;
		cout << "Nhap ngay nhap kho: ";
		cin >> s.ngay.ngay >> s.ngay.thang >> s.ngay.nam;
		cout << "Nhap vao trang thai";
		cin >> s.status;
		b = false;
	}
	else {
		system("cls");
		textcolor(11);
		cout << "Lua chon chuc nang" << endl;
		cout << "1.Xem thong tin sach" << endl;
		cout << "2.Them sach" << endl;
		cout << "3.Xoa sach" << endl;
		cout << "0.De thoat" << endl;
		textcolor(7);
		cout << "\n\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n";
		textcolor(12);
		cout << "Ma sach bi trung";
		textcolor(7);
		cout << endl;
		//system("pause");
	}
	}
}

void ghi_1_quyen_sach(ofstream& fileout,SACH& s) {
	
	fileout.open("Sach1.txt", ios_base::app);
	fileout << endl;
	fileout << s.ma << ", ";
	fileout << s.ten << ", ";
	fileout << s.nxb << ", ";
	fileout << s.gia<< ", ";
	fileout << s.nam << ", ";
	fileout << s.page << ", ";
	fileout << s.ngay.ngay << "/" << s.ngay.thang << "/" << s.ngay.nam << ", ";
	fileout << s.status;
	fileout.close();
}
void doc_all_sach(ifstream& filein, LIST& l) {
	while (!filein.eof()) {
		SACH s;
		//Đọc thông tin 1 quyển sách
		doc_1_quyen_sach(filein,s);
		//Khởi tạo node
		NODE* p = getNode(s);
		AddTail(l, p);
	}

}

void xuat(SACH s) {
	textcolor(12);
	cout << setw(10) << left << s.ma << setw(20) << left << s.ten << setw(20) << left << s.nxb;
	cout << setw(10) << left << s.gia<< setw(6) << left << s.nam << setw(10) << left << s.page;
	cout << setw(18) << left << s.status << setw(2) << s.ngay.ngay <<"/"<<s.ngay.thang<<"/"<<s.ngay.nam<< endl;
	textcolor(7);
}
void xuat_tat_ca_sach(list l) {
	
	for (NODE* p = l.head; p != NULL; p=p->next) {
		xuat(p->data);
	}
	giai_phong(l);
}
//Hàm giải phóng vùng nhớ cho danh sách liên kết
void giai_phong(LIST& l) {
	NODE* p = NULL;
	while (l.head != NULL) {
		p = l.head;
		l.head = l.head->next;
		delete(p);
	}
}
void quanly_sach() {
	int chon1;
	LIST a;
	SACH s;
	SACH ss;
	int n;
	NODE* p=new NODE();
	InitList(a);
	ifstream filein;
	ofstream fileout;
	bool menuconsach=true;
	while (menuconsach==true) {
		system("cls");
		textcolor(11);
		cout << "Lua chon chuc nang" << endl;
		cout << "1.Xem thong tin sach" << endl;
		cout << "2.Them sach" << endl;
		cout << "3.Xoa sach" << endl;
		cout << "0.De thoat" << endl;
		textcolor(7);
		cout << "\n\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n";
		cout << "Nhap vao lua chon: ";
		cin >> chon1;
		switch (chon1)
		{
		case 1:
			cout << "\n\n\t\t\t\tThong tin sach co trong thu vien\n\n";
			textcolor(16);
			cout << setw(10) << left << "Ma sach" << setw(20) << left << "Ten sach" << setw(20) << left << "Nha xuat ban";
			cout << setw(10) << left << "Gia" << setw(6) << left << "Nam" << setw(10) << left << "Trang"  
				<< setw(18)<<left  << "Trang thai" << setw(20) << left << "Ngay nhap kho" << endl;
			textcolor(7);
			filein.open("Sach1.txt", ios_base::in);
			doc_all_sach(filein, a);
			xuat_tat_ca_sach(a);
			filein.close();
			system("pause");
			break;
		case 2:
			system("cls");
			textcolor(11);
			cout << "Lua chon chuc nang" << endl;
			cout << "1.Xem thong tin sach" << endl;
			cout << "2.Them sach" << endl;
			cout << "3.Xoa sach" << endl;
			cout << "0.De thoat" << endl;
			textcolor(7);
			cout << "\n\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n";
			filein.open("Sach1.txt", ios_base::in);
			doc_all_sach(filein, a);
			nhap_thong_tin_sach(s, a, p);
			ghi_1_quyen_sach(fileout, s);
			filein.close();
			break;
		case 3:
			system("cls");
			textcolor(11);
			cout << "Lua chon chuc nang" << endl;
			cout << "1.Xem thong tin sach" << endl;
			cout << "2.Them sach" << endl;
			cout << "3.Xoa sach" << endl;
			cout << "0.De thoat" << endl;
			textcolor(7);
			cout << "\n\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n";
			cout << "Nhap vao ma sach can xoa: ";
			cin >> n;
			filein.open("Sach1.txt", ios::in);
			doc_all_sach(filein, a);
			remove("Sach1.txt");
			xoa(filein,a,n);
			ghi_tat_ca_sach(p, fileout, a);
			filein.close();
			system("pause");
			break;
		case 0:
			menuconsach=false;
			break;
		default:
			textcolor(12);
			cout << "Vui long nhap lai";
			textcolor(7);
			cout << endl;
			system("pause");
		}
	}
	
}
void xoa(ifstream& filein, LIST& l, int& n) {
	doc_all_sach(filein, l);
	NODE* p = l.head;
	NODE* q = NULL;
	if (l.head->data.ma==n) {
		l.head = l.head->next;
		delete p;
	}
	else {
	for (; p != NULL;p=p->next) {
		if (p->data.ma == n) {
			q->next = p->next;
			delete(p);
			break;
		}
			q = p;
	}
	}

}
void ghi_sau_xoa(NODE* p, ofstream& fileout) {
	fileout.open("Sach1.txt",ios::out|ios::out);
	fileout << endl;
	fileout <<p->data.ma << ", ";
	fileout << p->data.ten << ", ";
	fileout << p->data.nxb << ", ";
	fileout << p->data.gia << ", ";
	fileout << p->data.nam << ", ";
	fileout << p->data.page << ", ";
	fileout << p->data.ngay.ngay << "/" << p->data.ngay.thang << "/" << p->data.ngay.nam << ", ";
	fileout << p->data.status;
	fileout.close();
}
void ghi_tat_ca_sach(NODE* p, ofstream &fileout, LIST& l) {
	for (p = l.head; p != NULL; p = p->next) {
		ghi_sau_xoa(p, fileout);
	}
	giai_phong(l);
}

