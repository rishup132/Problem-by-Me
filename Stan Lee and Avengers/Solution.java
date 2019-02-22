/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * @author romit17
 */

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;

public class StanLee {
    
    int n, chainno, ptr;
    HashSet<Integer>[] adj;
    int[][] pa;
    int[] depth; int[] subsize; int[] chainhead;
    int[] chainind; int[] basearray; int[] posinbase; 
    long[] st; long[] lazy1; long[] lazy2;
    long mod = 1000000007;
    
    
    void solve() throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        StringBuilder sb = new StringBuilder("");
        int t = ni();
        while(t-->0)
        {            
            n = ni();
            int q =ni();
            initialise();
            
            for(int i=0;i<n-1;i++)
            {
                int x = ni()-1, y = ni()-1;
                adj[x].add(y);
                adj[y].add(x);
            }
            
            dfs(0, -1, 0);
            HLD(0, -1);
            
            for(int i=1;i<20;i++)
                for(int j=0;j<n;j++)
                    if(pa[i-1][j] != -1)
                        pa[i][j] = pa[i-1][pa[i-1][j]];
            
            while(q-->0)
            {
                int ty = ni(), l = ni()-1, r = ni()-1;
                if(ty == 1)
                {
                    long x = ni();
                    update(l,r,x);
                }
                else
                    System.out.println(query(l,r));
            }
        }
        
    }
    
    void update_treei(int node, int start, int end, int l, int r, long val)
    {
        if(lazy1[node] != 0)
        { 
            // This node needs to be updated
            long tmp = end-start;
            st[node] = (st[node] + ((end-start+1)*lazy1[node])%mod - (((tmp*(tmp+1)/2)%mod)*lazy2[node])%mod)%mod;    // Update it
            if(start != end)
            {
                lazy1[node*2+1] = (lazy1[node*2+1] + lazy1[node])%mod;
                lazy2[node*2+1] = (lazy2[node*2+1] + lazy2[node])%mod;
                lazy1[node*2+2] = (lazy1[node*2+2] + lazy1[node] - ((end-start)/2+1)*lazy2[node])%mod;
                lazy2[node*2+2] = (lazy2[node*2+2] + lazy2[node])%mod;                // Mark child as lazy
            }
            lazy1[node] = 0;                                  // Reset it
            lazy2[node] = 0;
        }
        if(start > end || start > r || end < l)              // Current segment is not within range [l, r]
            return;
        if(start >= l && end <= r)
        {
            // Segment is fully within range
            long tmp = end-start;
            st[node] = (st[node] + (end-start+1)*val + (tmp*(tmp+1)/2))%mod;
            if(start != end)
            {
                // Not leaf node
                lazy1[node*2+1] = (lazy1[node*2+1] + val)%mod;
                lazy2[node*2+1] = (lazy2[node*2+1] - 1)%mod;
                lazy1[node*2+2] = (lazy1[node*2+2] + val + (tmp/2+1))%mod;
                lazy2[node*2+2] = (lazy2[node*2+2] - 1)%mod;
            }
            return;
        }
        int mid = (start + end) / 2;
        long v1=0, v2=0;
        if(mid<l)
        {
            v1 = 0; v2 = val;
        }
        else if(mid>r)
        {
            v1 = val; v2 = 0;
        }
        else
        {
            v1 = val;
            if(start<l)
                v2 = (val + (mid-l+1))%mod;
            else
                v2 = (val + (mid-start+1))%mod;
        }
        update_treei(node*2+1, start, mid, l, r, v1);        // Updating left child
        update_treei(node*2 + 2, mid + 1, end, l, r, v2);   // Updating right child
        st[node] = st[node*2+1] + st[node*2+2];        // Updating root with max value 
    }
    
    void update_treed(int node, int start, int end, int l, int r, long val)
    {
        if(lazy1[node] != 0)
        { 
            // This node needs to be updated
            long tmp = end-start;
            st[node] = (st[node] + ((end-start+1)*lazy1[node])%mod - ((tmp*(tmp+1)/2)*lazy2[node])%mod)%mod;    // Update it
            if(start != end)
            {
                lazy1[node*2+1] = (lazy1[node*2+1] + lazy1[node])%mod;
                lazy2[node*2+1] = (lazy2[node*2+1] + lazy2[node])%mod;
                lazy1[node*2+2] = (lazy1[node*2+2] + lazy1[node] - ((end-start)/2+1)*lazy2[node])%mod;
                lazy2[2*node+2] = (lazy2[2*node+2] + lazy2[node])%mod;                // Mark child as lazy
            }
            lazy1[node] = 0;                                  // Reset it
            lazy2[node] = 0;
        }
        if(start > end || start > r || end < l)              // Current segment is not within range [l, r]
            return;
        if(start >= l && end <= r)
        {
            // Segment is fully within range
            long tmp = end-start;
            st[node] = (st[node] + (end-start+1)*val - (tmp*(tmp+1)/2))%mod;
            if(start != end)
            {
                // Not leaf node
                lazy1[node*2+1] = (lazy1[node*2+1] + val)%mod;
                lazy2[node*2+1] = (lazy2[node*2+1] + 1)%mod;
                lazy1[node*2+2] = (lazy1[node*2+2] + val - (tmp/2+1))%mod;
                lazy2[node*2+2] = (lazy2[node*2+2] + 1)%mod;
            }
            return;
        }
        int mid = (start + end) / 2;
        long v1=0, v2=0;
        if(mid<l)
        {
            v1 = 0; v2 = val;
        }
        else if(mid>=r)
        {
            v1 = val; v2 = 0;
        }
        else
        {
            v1 = val;
            if(start<l)
                v2 = (val - (mid-l+1))%mod;
            else
                v2 = (val - (mid-start+1))%mod;
        }
        update_treed(node*2+1, start, mid, l, r, v1);        // Updating left child
        update_treed(node*2 + 2, mid + 1, end, l, r, v2);   // Updating right child
        st[node] = st[node*2+1] + st[node*2+2];        // Updating root with max value 
    }
    
    void update_up2(int u, int v, long val)
    {
        int uchain, vchain = chainind[v];
        while(true)
        {
            uchain = chainind[u];
            if(uchain == vchain)
            {
                update_treed(0, 0, ptr-1, posinbase[v], posinbase[u], val);break;
            }
            long vv = val - (depth[chainhead[uchain]] - depth[v]);
            update_treed(0, 0, ptr-1, posinbase[chainhead[uchain]], posinbase[u], vv);
            u = chainhead[uchain];
            u = pa[0][u];
        }
    }

    
    long update_up1(int u, int v, long val)
    {
        int uchain, vchain = chainind[v];
        while(true)
        {
            uchain = chainind[u];
            if(uchain == vchain)
            {
                if(u==v) return val;
                val -= depth[u] - depth[v];
                update_treei(0, 0, ptr-1, posinbase[v]+1, posinbase[u], val+1);///////////
                return val;
            }
            val -= depth[u] - depth[chainhead[uchain]];
            update_treei(0, 0, ptr-1, posinbase[chainhead[uchain]], posinbase[u], val);
            u = chainhead[uchain];
            u = pa[0][u];
            val--;
        }
    }
    
    void update(int u, int v, long val)
    {
        int lca = LCA(u,v);
        long vv = update_up1(u,lca,val);
        update_up2(v,lca, vv);
    }
    
    long query_tree(int node, int start, int end, int l, int r)///////////l and r values
    {
        if(l>r) {throw new AssertionError("l r assertion failed");}
        
        if(start > end || start > r || end < l)
            return 0;         // Out of range
        
        if(lazy1[node] != 0)
        {
            // This node needs to be updated
            long tmp = end-start;
            st[node] = (st[node] + ((end-start+1)*lazy1[node])%mod - ((tmp*(tmp+1)/2)*lazy2[node])%mod)%mod;            // Update it
            if(start != end)
            {
                lazy1[node*2+1] = (lazy1[node*2+1] + lazy1[node])%mod;
                lazy2[node*2+1] = (lazy2[node*2+1] + lazy2[node])%mod;
                lazy1[node*2+2] = (lazy1[node*2+2] + lazy1[node] - ((end-start)/2+1)*lazy2[node])%mod;
                lazy2[2*node+2] = (lazy2[2*node+2] + lazy2[node])%mod;
            }
            lazy1[node] = 0;                 // Reset it
            lazy2[node] = 0;
        }
        
        if(start >= l && end <= r)             // Current segment is totally within range [l, r]
            return st[node];
        int mid = (start + end) / 2;
        long leftval = query_tree(node*2+1, start, mid, l, r);         // Query left child
        long rightval = query_tree(node*2 + 2, mid + 1, end, l, r); // Query right child
        long valuetoreturn =  (leftval + rightval)%mod;// do some operation here
        return valuetoreturn;
    }
    
    long query_up(int u, int v, boolean lside)
    {        
        int uchain, vchain = chainind[v];
        long ans = 0;
        while(true)
        {
            uchain = chainind[u];
            if(uchain == vchain)
            {
                if(lside)
                {
                    if(u==v) break;
                    ans = (ans + query_tree(0, 0, ptr-1, posinbase[v]+1, posinbase[u]))%mod;
                    break;
                }
                ans = (ans + query_tree(0, 0, ptr-1, posinbase[v], posinbase[u]))%mod;                
                break;
            }
            ans = (ans + query_tree(0,0,ptr-1, posinbase[chainhead[uchain]], posinbase[u]))%mod;
            u = chainhead[uchain];
            u = pa[0][u];            
        }
        return ans;
    }
    
    long query(int u, int v)
    {
        int lca = LCA(u,v);
        long a1 = query_up(u, lca, true);
        long a2 = query_up(v, lca, false);
        return (a1+a2)%mod;
    }
    
//    void make_tree(int cur, int s,  int e)
//    {
//        if(s == e-1)
//        {
//            tr[s] = cur; return;
//        }
//        
//        int c1 = cur<<1, c2 = cur|1, m = (s+e)>>1;
//        make_tree(c1, s, m);
//        make_tree(c2, m, e);
//            
//    }
    
    int LCA(int u, int v)
    {
        if(depth[u] < depth[v]) {u^=v;v^=u;u^=v;}
        int diff = depth[u] - depth[v];
        for(int i=0; i<20; i++) if( ((diff>>i)&1) != 0) u = pa[i][u];
    if(u == v) return u;
    for(int i=20-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
        u = pa[i][u];
        v = pa[i][v];
    }
        return pa[0][u];
    }
    
    void HLD(int cur, int prev)
    {
        if(chainhead[chainno] == -1)
            chainhead[chainno] = cur; 
        
        chainind[cur] = chainno;
        posinbase[cur] = ptr;
        basearray[ptr++] = 0;
        
        int sc = -1;
        for(int v:adj[cur])
        {
            if(v==prev) continue;
            if(sc == -1 || subsize[sc] < subsize[v])
                sc = v;
        }
        
        if(sc != -1)
            HLD(sc, cur);
        
        for(int v:adj[cur])
        {
            if(v == prev || v==sc) continue;
            chainno++;
            HLD(v, cur);
        }
        
    }
    
    void dfs(int cur, int prev, int dep)
    {
        pa[0][cur] = prev;
        depth[cur] = dep;
        subsize[cur] = 1;
        
        for(int v:adj[cur])
        {
            if(v == prev) continue;
            dfs(v, cur, dep+1);
            subsize[cur] += subsize[v];
        }
    }
    
    void initialise()
    {
        chainno=0; ptr=0;
        
        adj = new HashSet[n];
        for(int i=0;i<n;i++)
            adj[i] = new HashSet<>();
        
        pa = new int[20][n];
        for(int i=0;i<pa.length;i++)
            Arrays.fill(pa[i], -1);
        
        depth = new int[n];
        subsize = new int[n];
        chainhead = new int[n];
        Arrays.fill(chainhead, -1);
        chainind = new int[n];
        basearray = new int[n];
        posinbase = new int[n]; 
        st = new long[n*4];
        lazy1 = new long[n*4];
        lazy2 = new long[n*4];        
    }
    
    public static void main(String[] args) throws IOException {
        new StanLee().solve();
    } 
    
    private byte[] inbuf = new byte[1024];
    public int lenbuf = 0, ptrbuf = 0;    
    InputStream is = System.in;

    private int readByte() {
        if (lenbuf == -1) {
            throw new InputMismatchException();
        }
        if (ptrbuf >= lenbuf) {
            ptrbuf = 0;
            try {
                lenbuf = is.read(inbuf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (lenbuf <= 0) {
                return -1;
            }
        }
        return inbuf[ptrbuf++];
    }
    
    private boolean isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }
    
    private int skip() {
        int b;
        while ((b = readByte()) != -1 && isSpaceChar(b));
        return b;
    }
    
    private double nd() {
        return Double.parseDouble(ns());
    }
    
    private char nc() {
        return (char) skip();
    }
    
    private String ns() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    
    private char[] ns(int n) {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while (p < n && !(isSpaceChar(b))) {
            buf[p++] = (char) b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }
    
    private char[][] nm(int n, int m) {
        char[][] map = new char[n][];
        for (int i = 0; i < n; i++) {
            map[i] = ns(m);
        }
        return map;
    }
    
    private int[] na(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = ni();
        }
        return a;
    }
    
    private int[] na1(int n) {
        int[] a = new int[n + 1];
        for (int i = 1; i < n + 1; i++) {
            a[i] = ni();
        }
        return a;
    }
    
    private long[] nb(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nl();
        }
        return a;
    }
    
    private long[] nb1(int n) {
        long[] a = new long[n + 1];
        for (int i = 1; i < n + 1; i++) {
            a[i] = nl();
        }
        return a;
    }
    
    private int ni() {
        int num = 0, b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        
        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    private long nl() {
        long num = 0;
        int b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        
        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
}

/*
1
12 20
12 1
1 4
2 12
2 5
2 6
3 12
3 7
3 8
3 10
10 11
8 9
*/

/*
2
4 4
1 2
4 1
1 3
2 2 4
1 3 4 4
1 1 2 3
2 2 4
6 5
2 5
2 3
4 1
5 6
1 2
1 4 6 10
1 6 4 10
1 3 5 5
2 3 4
2 1 6

*/