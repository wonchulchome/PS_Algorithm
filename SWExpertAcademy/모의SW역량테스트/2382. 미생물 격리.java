package day0903;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_2382 {
	public static int ans;
	public static int[][] map;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		for(int tc = 1; tc <= T; tc++) {
			ans = 0;//총 미생물 수
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			
			Microbe[] m = new Microbe[K];
			
			int x,y,cnt,dir;
			
			map = new int[N][N];
			
			//약품구역은 -2, 빈공간은 -1로 초기화
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(i==0 || j==0 || i==N-1 || j==N-1) {
						map[i][j] = -2;
					} else {
						map[i][j] = -1;
					}
				}
			}
			
			//미생물 입력
			for(int i=0; i<K; i++) {
				st = new StringTokenizer(br.readLine());
				x = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());
				cnt = Integer.parseInt(st.nextToken());
				dir = Integer.parseInt(st.nextToken());
				m[i] = new Microbe(x,y,cnt,dir);
				map[x][y] = i;//해당 맵에 미생물 index값 저장
			}
			
			//시뮬레이션
			for(int i=0; i<M; i++) {
				for(int j=2; j<N-2; j++) {
					for(int k=2; k<N-2; k++) {
						if(map[i][j] == -1) {
							
						} else {
							
						}
					}
				}
			}
			
			System.out.println("#"+tc+" "+ans);
		}//end of testCase
	}//end of main
	
	//미생물 클래스
	public static class Microbe{
		int x;//세로위치
		int y;//가로위치
		int cnt;//미생물 수
		int dir;//이동방향(상,하,좌,우) : 1,2,3,4
		
		public Microbe(int x, int y, int cnt, int dir) {
			this.x = x;
			this.y = y;
			this.cnt = cnt;
			this.dir = dir;
		}
		
	}//end of class
}//end of class
