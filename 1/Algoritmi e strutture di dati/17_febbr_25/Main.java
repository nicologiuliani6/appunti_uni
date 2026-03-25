public class Main {
    public class EXIT{
        public static final int SUCCES = 0;
        public static final int FAILURE = 1;
    }

    public static class List{
        int val;
        List next;
        List(){
            this.val = -1;
            this.next = null;
        }
        public void push(int val){
            List NewNode = new List();
            NewNode.val = val;
            if (this.next == null){
                this.next = NewNode;
            }
            else {
                List current = this.next;
                while (current.next != null){
                    current = current.next;
                }
                current.next = NewNode;
            }
        }
        public void print(){
            List TMP = this.next;
            while(TMP != null){
                System.out.println(TMP.val + " ");
                TMP = TMP.next;
            }
        }
    }
    public static void main(String[] args) {
        try{
            List L = new List();
            L.push(10);
            L.push(20);
            L.push(30);
            L.print();

            System.exit(EXIT.SUCCES);
        }
        finally{
            System.exit(EXIT.FAILURE);
        }
        
    }
}
