 bool isPalindrome(int x) {
        
        if (x < 0) return false;
        
        int half = 0;
        int fast = x;
        
        while(fast)
        {
            half = half * 10 + x%10;
            x = x/10;
            fast /= 100;
        }
        
        if(x == half || x == half/10) return true;
        else return false;
        
           }
