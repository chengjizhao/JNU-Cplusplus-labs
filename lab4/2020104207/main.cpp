int main() 
{
    SALES::Sales s1, s2;
    double ar1[SALES::QUARTERS] = {1000,2000,1500,1800};
     double ar2[SALES::QUARTERS] = {1200,2200,1300,1900};
    SALES::setSales(s1, ar1, SALES::QUARTERS);
    SALES::setSales(s2, ar2, SALES::QUARTERS);
    SALES::showSales(s1);
    SALES::showSales(s2);
    return0;
}