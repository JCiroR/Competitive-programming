import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
  	static int[] tablero;
    public static boolean[][] casillasInh;

    public static void main(String[] args) throws Exception  {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      try {
        String line = "";
        int temp = 0;
        int resultado = -1;
        int caso = 0;
        while((temp = Integer.parseInt(br.readLine())) != 0) {
          caso++;
        	casillasInh = new boolean[temp][temp];
          for(int i = 0; i < temp; i++) {
          	  line = br.readLine();
              for(int j = 0; j < temp; j++) 	
                 if(line.charAt(j) == '*') casillasInh[i][j] = true;
          }
          
          tablero = new int[temp];
          for(int i = 0; i < temp; i++)
            tablero[i] = -1;
          resultado = auxUbicarNR(0);
          System.out.println("Case " + caso + ": "+ resultado);
        }
      } catch (Exception e) {
        e.printStackTrace();
      }
    }

    static int auxUbicarNR(int columnaEnLaQueTrabajo) {
      if(columnaEnLaQueTrabajo == tablero.length) return 1;
      int contador = 0;
      for(int i = 0; i < tablero.length; i++) {
        if(puedoUbicarR(columnaEnLaQueTrabajo, i)) {
            tablero[columnaEnLaQueTrabajo] = i;
            contador += auxUbicarNR(columnaEnLaQueTrabajo + 1);
        }
      }
      tablero[columnaEnLaQueTrabajo] = -1;
      return contador;
    }    

  static boolean puedoUbicarR(int columna, int fila) {
    if(casillasInh[fila][columna]) return false;
    for(int i = 0; i < columna; i++)
      	if(tablero[i] == fila) return false;
    for(int i = 0; columna - i >= 0; i++) {
        if(tablero[i] == (fila + (columna - i))) return false;
      	if (tablero[columna - i] == fila - i || tablero[columna - i] == fila + i) return false;
    }
    return true;
  }
}