class Solution {
    fun solution(num_list: IntArray): Int {
        var first: Int = 0
        var second: Int = 0
        for(i:Int in 0..num_list.size-1){
            if(i%2==0){
                first += num_list[i];
            }else{
                second += num_list[i];
            }
        }
        
        var answer = if(first > second) first else second
        return answer
    }
}