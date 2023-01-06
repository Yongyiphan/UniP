
int main(void){
    int p1 = 1, p2 = 2, total = 0;
    for(int i = 5;i>=0;i--){
        total += (p1 + i) * (p2 + i);
    }

    return 0;
}