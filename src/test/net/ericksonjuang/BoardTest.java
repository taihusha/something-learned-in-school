package net.ericksonjuang;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import java.lang.reflect.Method;
import java.awt.*;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;


public class BoardTest {
    private static Board board;
    @Before
    public void setUp() {
        board=new Board();
    }
    @After
    public void tearDown() {
        System.out.println("teardown");
    }
    @Test
    public void init() {
        int[][] boardList = {{2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,1,0,2,2,2},
                {2,2,2,0,1,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2}};
        try {
            Method method1=board.getClass().getDeclaredMethod("init", new Class[]{});
            method1.setAccessible(true);
            method1.invoke(board);
        } catch (Exception e) {
            e.printStackTrace();
        }
        assertArrayEquals(boardList,board.getBoard());
    }
    @Test
    public void restart(){
        int[][] boardList = {{2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,1,0,2,2,2},
                {2,2,2,0,1,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2}};
        board.restart();
        assertArrayEquals(boardList,board.getBoard());
    }

    @Test
    public void getBlackPoint() {
        assertEquals(2,board.getBlackPoint());
    }

    @Test
    public void getWhitePoint() {
        assertEquals(2,board.getWhitePoint());
    }

    @Test
    public void getMoveCount() {
        assertEquals(0,board.getMoveCount());
    }
    @Test
    public  void getBoard() {
        int[][] boardList = {{2,2,2,2,2,2,2,2},
                             {2,2,2,2,2,2,2,2},
                             {2,2,2,2,2,2,2,2},
                             {2,2,2,1,0,2,2,2},
                             {2,2,2,0,1,2,2,2},
                             {2,2,2,2,2,2,2,2},
                             {2,2,2,2,2,2,2,2},
                             {2,2,2,2,2,2,2,2}};
        assertArrayEquals(boardList,board.getBoard());
    }
    @Test
    public void move() {
        assertEquals(false,board.move(State.BLACK,new Point(400, 200)));//无效走位
        assertEquals(false,board.move(State.WHITE,new Point(400,200)));//无效走位
        assertEquals(false,board.move(State.BLACK,new Point(340,300)));//重复的无效走位
        assertEquals(true,board.move(State.BLACK,new Point(280,240)));//有效走位
        assertEquals(true,board.move(State.WHITE,new Point(340,240)));//有效走位
        assertEquals(true,board.move(State.BLACK,new Point(400,240)));//有效走位
        assertEquals(true,board.move(State.WHITE,new Point(340,180)));//有效走位
    }
    @Test
    public void undo(){
        int[][] boardList = {{2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,1,0,2,2,2},
                {2,2,2,0,1,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2}};
        board.move(State.BLACK,new Point(280,240));
        board.undo();
        assertArrayEquals(boardList,board.getBoard());
    }
    @Test
    public void undoWithNoSet() {
        board.undo();
        int[][] boardList = {{2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,1,0,2,2,2},
                {2,2,2,0,1,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2}};
        assertArrayEquals(boardList,board.getBoard());
    }
    @Test
    public void getPlayerHistory() {
        assertEquals(true,board.move(State.BLACK,new Point(280,240)));//有效走位
        assertEquals(true,board.move(State.WHITE,new Point(340,240)));//有效走位
        int[] playerHistoryList = new int[64];
        playerHistoryList[0]=State.BLACK;
        playerHistoryList[1]= State.WHITE;
        assertArrayEquals(playerHistoryList,board.getPlayerHistory());
    }
    @Test
    public void hasValidMove() {
        assertEquals(true,board.hasValidMove(State.BLACK));
        assertEquals(true,board.hasValidMove(State.WHITE));
    }
    @Test
    public void getHistory() {
        int[][] boardList = {{2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,1,0,2,2,2},
                {2,2,2,0,1,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2},
                {2,2,2,2,2,2,2,2}};
        assertArrayEquals(boardList,board.getBoard());
    }

    @Test
    public void isGameOver() {
        assertEquals(false,board.isGameOver(State.BLACK));
    }
}