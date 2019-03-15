"""
Example written for Qxf2 Services' blog post on Python Unit Checking
Check if IsCheckmate method in ChessRules class calls GetListOfValidMoves  
Assert that it called at least once with some expected argument
"""
import unittest, mock
import ChessRules 
from ChessBoard import ChessBoard
 
class CheckIsCheckmate(unittest.TestCase):
    "Class to unit check the IsCheckmate method of ChessRules.py module"
    # creating a mock for GetListOfValidMoves
    @mock.patch('ChessRules.ChessRules.GetListOfValidMoves')        
    def test_called_with_args(self, mockGetListOfValidMoves):
        "Unit test for ChessRules method: IsCheckmate"
 
        # Creating objects of Chessboard and ChessRules class and calling IsCheckmate function with each piece for initial position and "black" color
        cb = ChessBoard(0) #Create a chess board object with the initial position
        chess_rules_obj = ChessRules.ChessRules()
        chess_rules_obj.IsCheckmate(cb.GetState(),"black")
 
        # Create expected_arg_calls list which is supposed to be called with GetListOfValidMoves for initial position
        # IsCheckmate calls GetListOfValidMoves with arguments: board, color (who is to play?) and co-ordinates of a square with a piece on it
        expected_arg_calls = []
        for row in range(0,2):
            for col in range(0,8):
                expected_arg_calls.append(mock.call(cb.GetState(), 'black', (row, col)))
 
 
        # assert that method was called at least once with some argument        
        mockGetListOfValidMoves.assert_any_call(cb.GetState(),"black",(1,6))
 
 
if __name__=="__main__":
    unittest.main()
