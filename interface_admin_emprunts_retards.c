#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_interfaces.h"
#include "user_structus.h"

typedef struct Emprunt Emprunt;

void   choisir_emprunts( GtkComboBox *combo,
            gpointer     data )
{

    /*gchar *string = gtk_combo_box_get_active_text( combo );
    g_print( "%s \n", ( string ? string : "NULL" ) );*/


}


void interface_admin_emprunt_retard (GtkWidget *window)
{

 GtkWidget *vbox,*hbox;

  GtkWidget *toolbar,*button,*button1,*label,*label1,*label2,*label3,*label4,*label5,*label6,*label7,*label8,*label9;
  GtkToolItem *newTb;
  GtkToolItem *openTb;
  GtkToolItem *saveTb;
  GtkToolItem *sep;
  GtkToolItem *exitTb;
  GtkWidget *table;
  GtkWidget *combo;





  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);
  gtk_window_set_title(GTK_WINDOW(window), "ADMIN");

  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);





/* tolllllbarr ************************ */
  toolbar = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

  newTb = gtk_tool_button_new_from_stock(GTK_STOCK_HOME);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), newTb, -1);

  openTb = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);

  saveTb = gtk_tool_button_new_from_stock(GTK_STOCK_ADD);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);

  saveTb = gtk_tool_button_new_from_stock(GTK_STOCK_EDIT);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);

  sep = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1);

  exitTb = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exitTb, -1);

  gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);

  g_signal_connect(G_OBJECT(exitTb), "clicked",
        G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);
/* ******************************************************************* */
/*  ******************* recherche **************************** */
hbox = gtk_hbox_new(FALSE, 0);
combo = gtk_combo_box_new_text();
    gtk_container_add( GTK_CONTAINER( hbox ), combo );
    gtk_combo_box_append_text( GTK_COMBO_BOX( combo ), "emprunts en cours" );
    gtk_combo_box_prepend_text( GTK_COMBO_BOX( combo ), "emprunts en retard" );
    gtk_combo_box_insert_text( GTK_COMBO_BOX( combo ), 1, "emprunts en attente" );
 g_signal_connect( G_OBJECT( combo ), "changed",
                      G_CALLBACK(choisir_emprunts), NULL );



//********************************************//


int x =  Nombre_Emprunts_En_Reatrd();
struct Emprunt  emprunts_retard[x];

 liste_Emprunts_en_retard(emprunts_retard);



//***************************************/






  gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);
/* ****************************************** */

/* ************** table ************************/
table = gtk_table_new(5, 4, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);
  int i,j;

   gchar *str = "<b>UTILISATEUR</b>";
  label2=gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(label2), str);

  gchar *str1 = "<b>TITRE</b>";
  label3=gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(label3), str1);

  gchar *str2 = "<b>DATE DEBUT</b>";
  label8=gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(label8), str2);

  gchar *str3 = "<b>DATE FIN</b>";
  label9=gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(label9), str3);


  gtk_table_attach_defaults(GTK_TABLE(table), label2, 0,1, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(table), label3, 1,2, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(table), label8, 2,3, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(table), label9, 3,4, 0, 1);

for (i=1; i < 5; i++) {
    label=gtk_label_new("122");
    gtk_table_attach_defaults(GTK_TABLE(table), label, 0,1, i, i+1);
    label1=gtk_label_new("122333");
    gtk_table_attach_defaults(GTK_TABLE(table), label1, 1,2, i, i+1);
    label6=gtk_label_new("122");
    gtk_table_attach_defaults(GTK_TABLE(table), label6, 2,3, i, i+1);
    label7=gtk_label_new("122");
    gtk_table_attach_defaults(GTK_TABLE(table), label7, 3,4, i, i+1);

  }
gtk_box_pack_start(GTK_BOX(vbox), table, FALSE, FALSE, 5);
/* **************************************************** */
  gtk_widget_show_all(window);

}
