angular.module('WritingChecker',[]).controller('mainController', function($http) {
    var vm = this;
    vm.rootURL = 'http://localhost:8080/WritingCheckerVisual/webresources/generic';
    
    //vm.display = false;
    vm.display = true;
    vm.data;
    vm.currentError;
    vm.currentErrorIndex = 0;
    vm.init = init;
    vm.nextError=nextError;
    vm.previousError=previousError;
    
    init();
    
    function init(){
        vm.data = {"words": [["I", "was", "serenaded", "by", "Cat", "Stevens", "and", "his", "guitar."],["Speaking", "of", "guitars,", "they", "may", "exemplify", "the", "art", "of", "usefulness", "in", "the", "art", "of", "scrap", "wood", "to", "the", "art", "of", "burying", "so", "that", "one", "may", "have", "rich,", "nutritious,", "and", "legit", "soil."],["Who", "do", "you", "-", "yes,", "you", "-", "think", "you", "should", "give", "my", "precious", "soil", "to?"],["Your", "friends", "can't", "digest", "them", "because", "of", "their", "metallic", "covered", "stomach", "that", "are", "made", "from", "plubnum", "by", "their", "parents."],["I", "think", "I", "legit", "very", "much", "quite", "like", "you", "because", "that's", "how", "the", "soil", "meatball", "bounces", "in", "my", "soil", "by", "the", "garden."],["Yours", "truly,", "Fred", "Schneider", "(writer", "of", "Rock", "Lobster", "-", "it's", "funny", "people)."]], "errors": [{"index": [0, 0], "message": "You used first person.", "word" : ""},{"index": [0, 3], "message": "You used the passive voice.", "word" : ""},{"index": [1, 29], "message": "You used extraneous words.", "word" : "legit"},{"index": [2, 2], "message": "You used second person.", "word" : ""},{"index": [2, 5], "message": "You used second person.", "word" : ""},{"index": [2, 8], "message": "You used second person.", "word" : ""},{"index": [2, 11], "message": "You used first person.", "word" : ""},{"index": [2, 14], "message": "You used extraneous words.", "word" : ""},{"index": [3, 0], "message": "You used second person.", "word" : ""},{"index": [3, 2], "message": "You used a contraction.", "word" : ""},{"index": [3, 14], "message": "You used the passive voice.", "word" : ""},{"index": [4, 0], "message": "You used first person.", "word" : ""},{"index": [4, 2], "message": "You used first person.", "word" : ""},{"index": [4, 3], "message": "You used extraneous words.", "word" : "legit"},{"index": [4, 4], "message": "You used extraneous words.", "word" : "very"},{"index": [4, 6], "message": "You used extraneous words.", "word" : "quite"},{"index": [4, 8], "message": "You used second person.", "word" : ""},{"index": [4, 10], "message": "You used a contraction.", "word" : ""},{"index": [4, 17], "message": "You used first person.", "word" : ""},{"index": [5, 0], "message": "You used second person.", "word" : ""},{"index": [5, 9], "message": "You used a contraction.", "word" : ""},{"index": [-1, -1], "message": "You frequently use this word.", "word" : "my"},{"index": [-1, -1], "message": "You frequently use this word.", "word" : "think"},{"index": [-1, -1], "message": "You frequently use this word.", "word" : "you"},{"index": [-1, -1], "message": "You frequently use this word.", "word" : "soil"},{"index": [-1, -1], "message": "You frequently use this word.", "word" : "art"},{"index": [-1, -1], "message": "You frequently use this word.", "word" : "legit"}]};
                    if(vm.data.errors.length > 0){
                vm.currentError = vm.data.errors[vm.currentErrorIndex];
            }else{
                vm.currentError = {"index": [-1,-1], "message": "No more suggestions", "word": ""};
            }
    }
    
    function nextError(){
        vm.currentErrorIndex++;
        if(vm.data.errors.length > vm.currentErrorIndex){
            vm.currentError = vm.data.errors[vm.currentErrorIndex];
        }else{
            vm.currentError = {"index": [-1,-1], "message": "No more suggestions", "word": ""};
            vm.currentErrorIndex = vm.data.errors.length;
        }
    }
    
    function previousError(){
        vm.currentErrorIndex--;
        if(vm.currentErrorIndex >= 0 && vm.data.errors.length > 0){
            vm.currentError = vm.data.errors[vm.currentErrorIndex];
        }else{
            vm.currentErrorIndex = 0;
        }
    }
    
});


