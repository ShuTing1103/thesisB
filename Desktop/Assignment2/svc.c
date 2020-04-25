#include "svc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TABLESIZE 1000000
/* function: svc_init 
* --------------------
* Initialize data structure used in svc (Hash Table)
*
*/
void *svc_init(void) {
    /* allocation */
    ht_t * hashTable = malloc(sizeof(ht_t));
    hashTable->entries = malloc(sizeof(entry_t*) * TABLESIZE);

    /* assignment */
    int i = 0; 
    for(; i < TABLESIZE; ++i){
        hashTable->entries[i] = NULL;
    }

}

/* function: cleanup
* ------------------
* clear all allocated memory used in svc
*
* helper: data structure will be cleared
*/
void cleanup(void *helper) {
    /*
  free(helper->entries);
    int i = 0; 
    for(; i < TABLESIZE; ++i){
        helper->entries[i] = NULL;
    }

  free(helper);
  helper = NULL;
  */
 return;
}

/* 
* Function: hash_file
* -------------------
* Compute a hash value of given file_path using following function:
*  
*   function file_hash(file_path)
*        file_contents = read(file_path)
*        file_length = num_bytes(file_contents)
*        hash = 0
*        for unsigned byte in file_path:
*            hash = (hash + byte) %1000
*        for unsigned byte in file_contents:
*           hash = (hash + byte) % 2000000000
*        return hash
*
* helper: structure will be used
* file_path: the given file_path
* returns: the hash value of corresponding file_path
*/

int hash_file(void *helper, char *file_path) {
    /* Declare and initialize */ 
    char *file_content = NULL;
    int file_path_length = 0; //length of the file name(num of char)
    int file_length = 0; //length of the file content(num of char)
    int hash = 0;

    /* Assign each variables */
    const char* ptr = file_path;
    while(*ptr++);
    file_path_length = ptr - file_path - 1;
   
    FILE* fptr = fopen(file_path, "r"); //open the file
    if(fptr != NULL){
        /* Go to the end of the file */
        if(fseek(fptr, 0L, SEEK_END) == 0){
            file_length = ftell(fptr) - 1; //assign file_length of the file_content
            if(file_length == -1){ 
                /* error*/
                return -2;
            }

            /* Allocate memory for file_content*/
            file_content = malloc(sizeof(char) * (file_length + 1));

            /* Go back to the start of the file*/
            if(fseek(fptr, 0L, SEEK_SET)!=0){
                /*error*/
                return -2;
            }

            /* Read the file into memory*/
            fread(file_content, sizeof(char), file_length, fptr);
        }
        fclose(fptr);
    }
    /* Start Compute hash value*/
    int sum = 0;
    for(int i = 0; i < file_path_length; i++){
        sum += file_path[i];
    }
    hash = sum % 1000;

    sum = 0;
    for(int i = 0; i < file_length; i++){
        sum += file_content[i];
    }
    printf("\n");
    hash = (sum + hash) % 2000000000;

    free(file_content);
    return hash;
}

/* function: svc_commit
* ---------------------
* Create a commit with the message given, and all changes to the files being tracked using following method:
 
* function get_commit_id(commit)
*    id = 0
*    for unsigned byte in commit.message:
*        id = (id + byte) % 1000
*    for change in commit.changes in increasing alphabetical order of file_name:
*        if change is addition, id = id + 376591
*        if change is deletion, id = id + 85973
*        if change is modification, id = id + 9573681
*        for unsigned byte in change.file_name:
*            id = (id * (byte % 37)) % 15485863 + 1
*    return id as hexadecimal string

* message: a char pointer points to a given message  
* return: return the commit id (char)
*/
char *svc_commit(void *helper, char *message) {
   
    /* if message is null, or no changes, return NULL*/
    if(message == NULL | strcmp(message, "No changes") == 0){
        return NULL;
    }
      /* Declaration and initialization */
    int id = 0;
    int message_len = 0;
 
    /* Assignment */
    //assign message_len
    const char* ptr = message;
    while(*ptr++);
    message_len = ptr - message - 1;
    printf("the message len is: %d\n", message_len);

    //assign 
  

    return NULL;
  
}

void *get_commit(void *helper, char *commit_id) {
    // TODO: Implement
    return NULL;
}

char **get_prev_commits(void *helper, void *commit, int *n_prev) {
    // TODO: Implement
    return NULL;
}

void print_commit(void *helper, char *commit_id) {
    // TODO: Implement
}

int svc_branch(void *helper, char *branch_name) {
    // TODO: Implement
    return 0;
}

int svc_checkout(void *helper, char *branch_name) {
    // TODO: Implement
    return 0;
}

char **list_branches(void *helper, int *n_branches) {
    // TODO: Implement
    return NULL;
}

/* function: svc_add
* ------------------
* add the file with given file_name into svc
* 
* file_name: given file_name
* return:
*        return corresponding hash value, if file successfully be added to the SVC system
*        return -1, if file_name is NULL
*        return -2, if file is already under version control
*        return -3, if file does not exist
*/
int svc_add(void *helper, char *file_name) {
    /* declaration and intialisation */
    int hash = 0; //target file's hash value

    /* erorrs 
    if(file_name == NULL){
        return -1;
    }
    if(is_file_under_svc(file_name) == 1)
    {
        return -2;
    }
    if(is_file_exist(file_name) == 0){
        return -3;
    }
    */
    /* Add file into SVC */

    return hash;
}

/* function: is_file_under_svc
* -----------------------------
*  check if the file with the given file_name is already under SVC
*   
* file_name: given file name
* return: 
*       return 1, if the file with given name is under SVC
*       return 0, if the file with given name is not under SVC

int is_file_under_svc(void* helper, char* file_name){
    return 0;
}
*/
/* function: is_file_exist
* ------------------------
* check if the file with given file_name is exist or not
*
* file_name: given file name
* return: 
*       return 1, if the file with given name exists.
*       return 0, if the file with given name does not exist.

int is_file_exist(void* helper, char* file_name){
    return 0;
}

*/
int svc_rm(void *helper, char *file_name) {
    // TODO: Implement
    return 0;
}

int svc_reset(void *helper, char *commit_id) {
    // TODO: Implement
    return 0;
}

char *svc_merge(void *helper, char *branch_name, struct resolution *resolutions, int n_resolutions) {
    // TODO: Implement
    return NULL;
}
