import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Player {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt(); // the total number of nodes in the level, including the gateways
        int L = in.nextInt(); // the number of links
        int E = in.nextInt(); // the number of exit gateways
        int[][] links = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                links[i][j] = 0;
            }
        }
        for (int i = 0; i < L; i++) {
            int N1 = in.nextInt(); // N1 and N2 defines a link between these nodes
            int N2 = in.nextInt();
            links[N1][N2] = 1;
            links[N2][N1] = 1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.err.print(links[i][j] + " ");
            }
            System.err.println("");
        }
        
        List<Integer> gateways = new ArrayList<Integer>();
        for (int i = 0; i < E; i++) {
            int EI = in.nextInt(); // the index of a gateway node
            gateways.add(EI);
        }

        // game loop
        while (true) {
            int SI = in.nextInt(); // The index of the node on which the Skynet agent is positioned this turn

            // Write an action using System.out.println()
            System.err.println("SI: " + SI);

            int rep = isLinkedToGateWay(links, gateways, SI);
            System.err.println("rep: " + rep);
            if (rep != -1) { //if this node is linked to a Gateway
                System.out.println(deleteLink(links, SI, rep));
                System.err.println(deleteLink(links, SI, rep));
            } else {
                System.out.println(isolateGateWay(links, gateways));
                System.err.println("HEHE" + isolateGateWay(links, gateways));
            }

            // Example: 0 1 are the indices of the nodes you wish to sever the link between
            //System.out.println(SI + " " + n);
        }
    }
    
    //Return -1 if not linked or gatewaynumber if linked to a gateway
    public static int isLinkedToGateWay(int[][] links, List<Integer> gateways, int node) {
        System.err.println("Kiem tra node " + node + " co lien ket gateway?");
        int ret = -1;
        int go = 1;
        int N = links[0].length;
        int i = 0;
        System.err.println("So node " + N);
        for (int k = 0; k < gateways.size() && go == 1; k++) {
            i = 0;
            while (go == 1 && i < N) {
                System.err.println("Links " + links[i][node]);
                if (links[i][node] == 1) {
                    System.err.println("Gateways " + gateways.get(k));
                    if (i != gateways.get(k)) {  //is i a gateway ? invert true false
                        go = 1;
                        i++;
                    } else {
                        go = 0;
                    }
                }
            }
        }
        if (go == 1) {
            ret = i;
        }
        return ret;
    }
    
    //Retrun the link to destroy near the first gateway in the list if there is a Gateway or Emptystring
    public static String isolateGateWay(int[][] links, List<Integer> gateways) {
        String ret = "";
        int N = links[0].length;
        int node = -1;
        int i = 0;
        if (gateways.size() > 0) {
            while (i < N && node == -1) {
                if (links[i][gateways.get(0)] != 0) {
                    node = i;
                } else {
                    node = -1;
                    i++;
                }
            }
        }
        System.err.println("HEHE: " + node);

        if (node != -1) {
            ret = node + " " + gateways.get(0);
            links[i][gateways.get(0)] = 0;
            links[gateways.get(0)][i] = 0;
        }

        return ret;
    }
    
    public static String deleteLink(int[][] links, int node, int gateway) {
        links[node][gateway] = 0;
        links[gateway][node] = 0;
        return (node + " " + gateway);
    }
}
