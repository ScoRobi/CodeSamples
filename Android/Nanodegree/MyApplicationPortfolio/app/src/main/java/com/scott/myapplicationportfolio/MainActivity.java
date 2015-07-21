package com.scott.myapplicationportfolio;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;


public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    /**
     * Called when the used pushes a button. Should display toast.
     * @param view The View associated with the button.
     */
    public void handleButtonPush(View view) {
        try {
            Toast toast = Toast.makeText(
                    view.getContext(),
                    String.format("%s clicked!", ((Button) view).getText()),
                    Toast.LENGTH_SHORT);
            toast.show();
        } catch (Exception ex) {
            System.out.println("Exception Caught: " + ex.getMessage());
        }
    }
}
