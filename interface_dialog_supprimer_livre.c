#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_structs.h"
#include "user_functions.h"
#include "user_interfaces.h"




 void on_click (GtkDialog *dialog,gint response_id, gpointer  user_data)
{
  /*For demonstration purposes, this will show the int value
  of the response type*/
  g_print ("response is %d \n", response_id);
  printf("user data est %d \n", user_data);

  if( response_id==-9)
  {
    gtk_widget_destroy (GTK_WIDGET (dialog));

  }
  else{



   Livre *book  = (Livre *)malloc(sizeof(Livre));
book = GetLivre(user_data);


int result = supprimer_livre(user_data);
printf("resultta de spprusesion est %d \n", result);
if(result==1)
{

printf("succés de suppression \n");

dialog_succes_suppression(dialog);

}
else{

printf("imposible de supprimer \n");
dialog_erreur_suppression(dialog);
}



  }

  /*This will cause the dialog to be destroyed*/

}





void interface_supprimer_livre(  GtkWidget *window, int idlivre)
 {


 printf("id livre est %d \n", idlivre);


  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_QUESTION,
            GTK_BUTTONS_YES_NO,
            "Vous etes sur de supprimer cet livre ?");
  gtk_window_set_title(GTK_WINDOW(dialog), "Question");
  gtk_dialog_run(GTK_DIALOG(dialog));
  g_signal_connect (GTK_DIALOG (dialog),
                    "response",
                   on_click,
                    idlivre);
 //gtk_widget_destroy(dialog);



}
