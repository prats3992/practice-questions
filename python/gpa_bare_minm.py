import itertools

# Grade values corresponding to grades
grades = {
    "A": 10,
    "A-": 9.25,
    "B+": 8.75,
    "B": 8,
    "B-": 7.25,
    "C+": 6.75,
    "C": 6,
    "C-": 5.25
}

# Course credits for Semester 5
course_credits = {
    "FOCS": 4,
    "TOC": 4,
    "SMAI": 4,
    "DL": 4,
    "SMB": 4,
    "ILGC": 2
}

total_sem5_credits = sum(course_credits.values())

# Required GPA for Semester 5
required_sem5_gpa = 7.9

# Initialize the worst-case grades (start with C+ for all except TOC which is fixed)
initial_grades = {
    "FOCS": "B-",
    "TOC": "B-",  # Fixed at B-
    "SMAI": "B-",
    "DL": "B-",
    "SMB": "B",   # Starts at B, can be upgraded
    "ILGC": "B-"
}

# Get all permutations of the remaining courses to try different upgrade orders
remaining_courses = ["FOCS", "SMAI", "DL", "SMB", "ILGC", "TOC"]
permutations = list(itertools.permutations(remaining_courses))

valid_cases = []

for perm in permutations:
    # Reset grades to the initial worst-case values
    worst_case_grades = initial_grades.copy()

    # Calculate total GPA based on initial worst-case grades
    total_gpa = 0
    for course, grade in worst_case_grades.items():
        total_gpa += grades[grade] * course_credits[course]
    
    # Calculate the current Semester 5 GPA
    current_sem5_gpa = total_gpa / total_sem5_credits

    # Index for iteration over the permutation
    i = 0

    # Upgrade grades for the current permutation until the target GPA is met
    while current_sem5_gpa < required_sem5_gpa and i < len(perm):
        course = perm[i]
        
        # Upgrade the current grade step by step (from C+ upwards)
        if worst_case_grades[course] == "C+":
            worst_case_grades[course] = "B-"
            total_gpa += (grades["B-"] - grades["C+"]) * course_credits[course]
        elif worst_case_grades[course] == "B-":
            worst_case_grades[course] = "B"
            total_gpa += (grades["B"] - grades["B-"]) * course_credits[course]
        elif worst_case_grades[course] == "B":
            worst_case_grades[course] = "B+"
            total_gpa += (grades["B+"] - grades["B"]) * course_credits[course]
        elif worst_case_grades[course] == "B+":
            worst_case_grades[course] = "A-"
            total_gpa += (grades["A-"] - grades["B+"]) * course_credits[course]
        
        # Recalculate GPA
        current_sem5_gpa = total_gpa / total_sem5_credits
        i += 1
        if i == len(perm):
            i = 0
    
    # If the GPA meets the target, store this permutation of grades as valid
    if current_sem5_gpa >= required_sem5_gpa:
        # append to valid_cases only if worst_case_grades is not in valid_cases, even if perm or current_sem5_gpa is same
        if worst_case_grades not in [case[1] for case in valid_cases]:
            valid_cases.append((perm, worst_case_grades.copy(), current_sem5_gpa))
        else:
            continue

# Output all valid grade combinations that meet or exceed the target GPA
print(f"Found {len(valid_cases)} valid combinations of grades that meet or exceed the target GPA:\n")

for idx, (perm, grades_combination, gpa) in enumerate(valid_cases):
    for course, _ in grades_combination.items():
        print(f"{course}")
    print(f"Case {idx + 1}:")
    for course, grade in grades_combination.items():
        # print(f"{course}: {grade} (Credits: {course_credits[course]})")
        print(f"{grade}")
    print(f"Resulting GPA: {gpa}\n")
