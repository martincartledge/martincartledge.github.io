class Student
{
public:
    Student(char student_id, char first_name, char last_name, char email_address, int age, int days_to_complete, char degree_program);

private:
    char student_id;
    char first_name;
    char last_name;
    char email_address;
    int age;
    int day_to_complete;
    char degree_program;

    // student_id
    char get_student_id();
    void set_student_id(char new_student_id);

    // first_name
    char get_first_name();
    void set_first_name(char new_first_name);
    // last_name
    char get_last_name();
    void set_last_name(char new_last_name);
    // email_address
    char get_email_address();
    void set_email_address(char new_email_address);
    // age
    int get_age();
    void set_new_age(int new_age);
    // days_to_complete
    int get_days_to_complete();
    void set_get_days_to_complete(int new_days_to_complete);
    // degree_program
    char get_degree_program();
    void set_degree_program(char new_degree_program);
};