#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

// n:10^5 h:10^9，还有一个问题这里计算面积会溢出
// 解题思路：用两个绝对单调递增单调栈(左右各一)，找一长方形条左右两边比它更小的长方形条的位置

typedef long long ll;
const int N = 1e5+100;  // 科学计数法
int arr[N], n, arrL[N], arrR[N];
stack<int> sal, sar;

ll calc_area() {
    memset(arrL, 0, sizeof arrL);  // 默认左右边界是0
	memset(arrR, 0, sizeof arrR);
    while(!sal.empty()) {
        sal.pop();
    }
    while(!sar.empty()) {
        sar.pop();
    }
    for (int i = 1; i <= n; i++) {  // 因为0为左边界，所以必须从1开始，这样在计算最大面积时才是正确的
        cin >> arr[i];
        /**
         * 思路：
         * 看了别人的答案想了半天才明白……其实可以把这个想象成锯木板，如果木板都是递增的那我很开心，
         * 如果突然遇到一块木板i矮了一截，那我就先找之前最戳出来的一块（其实就是第i-1块），
         * 计算一下这个木板单独的面积，然后把它锯成次高的，这是因为我之后的计算都再也用不着这块木板本身的高度了。
         * 再然后如果发觉次高的仍然比现在这个i木板高，那我继续单独计算这个次高木板的面积（应该是第i-1和i-2块），
         * 再把它俩锯短。直到发觉不需要锯就比第i块矮了，那我继续开开心心往右找更高的。当然为了避免到了最后一直都是递增的，
         * 所以可以在最后加一块高度为0的木板。
         * 这个算法的关键点是把那些戳出来的木板早点单独拎出来计算，然后就用不着这个值了。
         */ 

        // 使用单调栈快速寻找边界(O(n)，暴力O(n^2))：在 绝对单调递增栈 出栈时，找到左右边界。
        // 求右边界)
        while(!sar.empty() && arr[sar.top()] >= arr[i]) {
            arrR[sar.top()] = i;  // 循环出栈中，多个出栈元素的右边界)都是当前元素i，记录左边界
            sar.pop();  // 大于等于i的元素都出栈，之后不考虑
        }
        sar.push(i);
        // 求左边界(
        while (!sal.empty() && arr[sal.top()] >= arr[i]) {
            sal.pop();  // 出栈的都是比arr[i]高的
        }
        if (!sal.empty() && arr[sal.top()] < arr[i]) {
            arrL[i] = sal.top();  // 循环出栈后，当前元素i的左边界(是栈中(自顶向下)第一个小于i的元素(即栈顶)，记录右边界
        }
        sal.push(i);  // 大于等于i的元素都出栈，之后不考虑
    }

	for(int i=1;i<=n;i++) cout<<arrL[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++) cout<<arrR[i]<<" ";cout<<endl;
    
    // 求不同长方形条扩展的面积中最大的
    ll ret = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (arrR[i] == 0) {
            arrR[i] = n + 1;
        }
        sum = arr[i] * (arrR[i] - arrL[i] - 1ll);  // 这里要1转成longlong型
        ret = max(sum, ret);
    }
    return ret;
}

int main()
{
    ll ans;
    while (cin >> n && n) {
        ans = calc_area();
        cout << ans << endl;
    }
    return 0;
}