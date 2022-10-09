class Student {
    public:
        Student(string student_id, string first_name, string last_name, string email_address, int age, int days_to_complete, string degree_program);
        
    private:
        string student_id;
        string first_name;
        string last_name;
        string email_address;
        int age;
        int day_to_complete;
        string degree_program;
        
        // student_id
        string get_student_id();
        void set_student_id(string new_student_id);
        
        // first_name
        string get_first_name();
        void set_first_name(string new_first_name);
        // last_name
        string get_last_name();
        void set_last_name(string new_last_name);
        // email_address
        string get_email_address();
        void set_email_address(string new_email_address);
        // age
        int get_age();
        void set_new_age(int new_age);
        // days_to_complete
        int get_days_to_complete();
        void set_get_days_to_complete(int new_days_to_complete);
        // degree_program
        string get_degree_program();
        void set_degree_program(string new_degree_program);
};