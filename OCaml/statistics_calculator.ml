let read_numbers () =
  let line = read_line () in
  let numbers =
    String.split_on_char ' ' line
    |> List.filter (fun s -> s <> "")
    |> List.map int_of_string
  in
  numbers

let calculate_mean numbers =
  let sum = List.fold_left (+) 0 numbers in
  float_of_int sum /. float_of_int (List.length numbers)

let calculate_median numbers =
  let sorted_numbers = List.sort compare numbers in
  let len = List.length sorted_numbers in
  if len mod 2 = 0 then
    let mid1 = List.nth sorted_numbers (len / 2 - 1) in
    let mid2 = List.nth sorted_numbers (len / 2) in
    float_of_int (mid1 + mid2) /. 2.0
  else
    float_of_int (List.nth sorted_numbers (len / 2))

let calculate_mode numbers =
    let counts = Hashtbl.create 100 in
    List.iter (fun n ->
        let count = try Hashtbl.find counts n with Not_found -> 0 in
        Hashtbl.replace counts n (count + 1)
    ) numbers;
    let max_count = ref 0 in
    let mode = ref [] in
    Hashtbl.iter (fun n count ->
        if count > !max_count then begin
            max_count := count;
            mode := [n]
        end else if count = !max_count then
            mode := n :: !mode
    ) counts;
    !mode

let print_results numbers =
  if List.length numbers = 0 then
    print_endline "No numbers provided."
  else
    let mean = calculate_mean numbers in
    let median = calculate_median numbers in
    let mode = calculate_mode numbers in
    print_string "Mean: "; (* Added "Mean: " *)
    print_float mean; print_newline ();
    print_string "Median: "; (* Added "Median: " *)
    print_float median; print_newline ();
    print_string "Mode: ";
    List.iter (fun x -> print_int x; print_string " ") mode;
    print_newline ()

let () =
  print_endline "Statistics Calculator";
  print_endline "Enter numbers separated by spaces:";
  let numbers = read_numbers () in
  print_results numbers
;;
