#include<iostream>
#include<cstring>
using namespace std;

class HANGHOA{
    protected:
        char mahanghoa[30];
        char tenhanghoa[30];
        float dongia;
    public:
        HANGHOA(){
            strcpy(mahanghoa,"");
            strcpy(tenhanghoa,"");
            dongia = 0;
        }
        HANGHOA(char *mahanghoa,char *tenhanghoa, float dongia){
            strcpy(this->mahanghoa,mahanghoa);
            strcpy(this->tenhanghoa,tenhanghoa);
            this->dongia = dongia;
        }
        ~HANGHOA(){
        }
        void nhap(){
            cout<<"\nNhap ma hang hoa: ";
            cin>>mahanghoa;
            cout<<"\nNhap ten hang hoa: ";
            cin>>tenhanghoa;
            cout<<"\nNhap don gia: ";
            cin>>dongia;
        }
        void xuat(){
            cout<<"\nMa hang hoa:"<<mahanghoa<<endl;
            cout<<"\nTen hang hoa:"<<tenhanghoa<<endl;
            cout<<"\nDon gia:"<<dongia<<endl;
        }
        float getDonggia(){
            return dongia;
        }
        char *getMahanghoa(){
            return mahanghoa;
        }
        char *getTenhanghoa(){
            return tenhanghoa;
        }
};

class MT: public HANGHOA{
    private:
        float tocdo;
        int soluong;
    public:
        MT(){
            tocdo = 0;
            soluong = 0;
        }
        MT(float tocdo, int soluong): HANGHOA(mahanghoa,tenhanghoa,dongia){
            this->tocdo = tocdo;
            this->soluong = soluong;
        }
        ~MT(){
        }
        friend istream &operator>>(istream &is, MT &mt){
            mt.nhap();
            cout<<"\nNhap toc do: ";
            is>>mt.tocdo;
            cout<<"\nNhap so luong: ";
            is>>mt.soluong;
            return is;
        }
        friend ostream &operator<<(ostream &os, MT &mt){
            mt.xuat();
            os<<"\nToc do: "<<mt.tocdo<<endl;
            os<<"\nSo luong: "<<mt.soluong<<endl;
            os<<"\nThanh tien: "<<mt.thanhtien()<<endl;
            return os;
        }

        float thanhtien(){
            return soluong * dongia;
        }
        float gettocdo(){
            return tocdo;
        }
};

class MTXT: public MT{
    private:
        float trongluong;
    public:
        MTXT(){
            trongluong = 0;
        }
        MTXT(char *mahanghoa ,char *tenhanghoa, float dongia, float tocdo, int soluong, float trongluong): MT(tocdo, soluong){
            this->trongluong = trongluong;
        }
        ~MTXT(){}
        friend istream &operator>>(istream &is, MTXT &mtxt){
            is>>(MT&) mtxt;
            cout<<"\nNhap trong luong: ";
            is>>mtxt.trongluong;
        }
        friend ostream &operator<<(ostream &os, MTXT &mtxt){
            os<<(MT&) mtxt;
            os<<"\nTrong luong: "<<mtxt.trongluong<<endl;
        }
        float phibaotri(){
            return getDonggia() * 95/100;
        }
};

int main(){
    int n;
    cout<<"\nNhap so luong may tinh sach tay: ";
    cin>>n;
    MTXT *mtxt = new MTXT[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"\nNhap may tinh sach tay thu"<<i+1<<endl;
        cin>>mtxt[i];
    }
    cout<<"\nDanh sach may tinh sach tay vua nhap: "<< endl;
    for (int i = 0; i < n; i++)
    {
        cout<<mtxt[i];
    }
    // tim theo ma
    char timma[30];
    cout<<"\nNhap ma can tim: ";
    fflush(stdin);
    cin.getline(timma,30);
    for (int i = 0; i < n; i++)
    {
        if(strcmpi(timma,mtxt[i].getMahanghoa())==0){
            cout<<mtxt[i];
        }
    }
    //liet ke may tinh
    cout<<"\nLiet ke may tinh: "<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<"\nMay tinh thu"<<i+1<<endl;
            cout<<mtxt[i].getTenhanghoa();
        }
        
    //tong phi bao tri
    cout<<"\nTong phi bao tri"<<endl;
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + mtxt[i].phibaotri();
    }
    cout<<"\nSum phibaotri: "<<sum<<endl;
    //tim may co toc do nho nhat
    cout<<"\nTim may tinh co toc do lon nhat: "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(mtxt[i].gettocdo() > mtxt[j].gettocdo()){
                MTXT temp;
                temp = mtxt[i];
                mtxt[i] = mtxt[j];
                mtxt[j] = temp;
            }
        }
        
    }
    cout<<mtxt[n-1]<<endl;
    //sua thong tin 1 may tinh
    char tenmay[30];
    cout<<"\nNhap ten may tinh : ";
    fflush(stdin);
    cin.getline(tenmay,30);
    for (int i = 0; i < n; i++)
    {
        if(strcmpi(tenmay,mtxt[i].getTenhanghoa())==0){
            cin>>mtxt[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<mtxt[i];
    }
    

    //xoa thong tin 1 may tinh theo ma
    char xoama[30];
    cout<<"\nNhap ma can xoa: ";
    fflush(stdin);
    cin.getline(xoama,30);
    for (int i = 0; i < n-1; i++)
    {
        if(strcmpi(xoama,mtxt[i].getMahanghoa())==0){
            mtxt[i] = mtxt[i+1];
        }
    }
    n--;
    for (int i = 0; i < n; i++)
    {
        cout<<mtxt[i];
    }
    

    //chen 1 may tinh vao vi tri k
    int k;
    cout<<"\nNhap vao vi tri k: ";
    cin >> k;
    cout<<"\nNhap thong tin chen: "<< endl;
    cin>>mtxt[k];
    for (int i = n; i >= k; i--){
        mtxt[i] = mtxt[i-1];
    }
    n++;
    for (int i = 0; i < n; i++)
    {
        cout<<mtxt[i];
    }
    
    //sap xep tang dan cua ma may tinh
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(strcmpi(mtxt[i].getMahanghoa(), mtxt[j].getMahanghoa())>0){
                MTXT temp;
                mtxt[i] = mtxt[j];
                mtxt[j] = temp;
            }
        }
        
    }
    for (int i = 0; i < n ; i++)
    {
        cout<<mtxt[i];
    }
    
    
    return 0;
}
